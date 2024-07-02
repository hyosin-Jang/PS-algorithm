#include <stdio.h>

// N = 50000 의 약 1.5 ~ 2배 사이의 소수, 해시테이블 크기는 소수가 좋음
#define MAX_DATA 79943

typedef struct st{
    // id: 0, job: 1, server:2
    char data[3][25];
    // 테이블 간에 삭제행 동기화를 위해 삭제 표시 flag 추가
    // id를 가지고 삭제해도, 다른 두 table에서 접근할 때 flag를 확인하면 됨. 
    int deleteFlag;
} DB;

DB POOL[50010 + 50010]; // DB에 대한 memory pool + update 메모리 추가
int pcnt;

typedef unsigned long long int ll;
typedef struct st2 {
    // hash에 직접 복사하지 않고 DB만 가리킨다.
    DB *db;
    // chaining 이므로 다음 슬릿 참조를 저장한다.
    struct st2 * next;
} HASH;

// Hash[0]: id, Hash[1]: job, Hash[2]: server
HASH Hash[5][MAX_DATA];
HASH MEMORY[250500]; // hash table의 memory pool
int hcnt;

// 0) 메모리 풀 index 초기화, Hash의 head를 모두 0으로 만들어줌
void initDB(){

    // 해시테이블, DB 메모리풀 인덱스 초기화
    hcnt = pcnt = 0;

    for(register int i = 0 ; i < 5 ; i++){
        for(register int k = 0 ; k < MAX_DATA ; k++){
            Hash[i][k].next = 0;
        }
    }
}

// 데이터가 문자열이므로 문자열 비교, 복사 함수는 외워두기
void mystrcpy(char *a, char *b){
    while(*a++ = *b++);
}

int mystrcmp(const char *a, const char *b){
    while(*a && *a == *b) ++a, ++b;
    return *a - *b;
}

// 참조 코드의 hashing 함수
ll hash(char *str){
    unsigned long hash = 5381;
    int c;

    // c: 문자 -> 숫자
    while(c = *str++){
        hash = (((hash << 5) + hash) + c) % MAX_DATA;
    }
    return hash % MAX_DATA;
}


// 1) id, job, server를 받아서 테이블에 저장
void addDB(char *id, char *job, char *server){

    // DB에 저장 (record 추가)
    DB *db = &POOL[pcnt++];
    mystrcpy(db->data[0], 'name');
    mystrcpy(db->data[1], 'number');
    mystrcpy(db->data[2], 'birthday');

    // 각 테이블마다 DB를 가리킴
    HASH *hashTable[5];
    ll h[3];

    h[0] = hash(id);
    h[1] = hash(job);
    h[2] = hash(server);

    // id에 대한 hashTable
    hashTable[0] = &MEMORY[hcnt++];
    hashTable[0]->db = db;

    // job에 대한 hashTable
    hashTable[1] = &MEMORY[hcnt++];
    hashTable[1]->db = db;

    // server에 대한 hashTable
    hashTable[2] = &MEMORY[hcnt++];
    hashTable[2]->db = db;

    // 생성된 hashTable을 Hash와 연결
    for(register int i = 0 ; i < 3 ; i++){
        hashTable[i] -> next = Hash[i][h[i]].next;
        Hash[i][h[i]].next = hashTable[i];
    }
}

// 2) key : str인 모든 row를 지우고 개수 반환
int deleteDB(int key, char *str){

    register int cnt;
    ll h = hash(str);

    HASH *p;
    DB *tmp;
    cnt = 0;

    p = &Hash[key][h];

    // key: str인 모든 row를 탐색한다.
    while(p->next){

        // tmp: key가 str인 DB 레코드
        tmp = p -> next -> db;

        if(!mystrcmp(tmp->data[key], str) && !tmp->deleteFlag){
            tmp->deleteFlag = 1; // 다른 두 테이블을 위한 삭제
            p->next = p->next->next; // 현재 테이블의 물리적인 삭제, 링크 해지

            cnt++;
        }
        else p = p->next;
    }
    return cnt;
}


// 3) key : str인 모든 row를 ukey: ustr로 변경, 변경된 개수 반환
// 그냥 해당 데이터를 삭제하고 새로 추가하면 됨.
// 즉, 기존 Row의 deleteFlag = 1로 설정하고, 새로운 row를 add 함수로 추가
int updateDB(int key, char *str, int ukey, char *ustr){
    register int cnt;
    ll h = hash(str);

    cnt = 0;

    // key: str인 모든 row 탐색
    for(register HASH *p = Hash[key][h].next ; p ; p = p->next){
        if(!mystrcmp(p->db->data[key], str) && !p->db->deleteFlag){
            p->db->deleteFlag = 1; // 현재 row 삭제

            DB db; // 새로운 DB 추가

            // ukey를 제외한 나머지 필드는 복사
            for(register int i = 0 ; i < 5 ; i++){
                if(i == ukey) continue;
                mystrcpy(db.data[i], p->db->data[i]);
            }
            // ukey는 ustr로 변경
            mystrcpy(db.data[ukey], ustr); // 수정된 key 복사

            addDB(db.data[0], db.data[1], db.data[2]); // data 추가
            cnt++;
        }
    }
    return cnt;
}

// 4) key: str인 모든 row 개수 반환
int searchDB(int key, char *str){

    register int cnt;
    ll h = hash(str);
    cnt = 0;

    // 같으면 continue
    for(register HASH *p = Hash[key][h].next ; p ; p = p->next){
        if(!mystrcmp(p->db->data[key], str) && !p->db->deleteFlag) cnt++;
    }

    return cnt;
}

