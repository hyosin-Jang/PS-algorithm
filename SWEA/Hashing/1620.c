#include <stdio.h>

// MAX_TABLE을 바꿔가면서 memeory crash가 나는지 확인
#define MAX_TABLE 10007
typedef unsigned long long int ull;

int N, M;

ull hash(const char *str){
    unsigned long hash = 5381;
    int c;

    while(c = *str++){
        hash = (((hash << 5) + hash) + c) % MAX_TABLE;
    }

    return hash % MAX_TABLE;
}

void mystrcpy(char *a, const char *b){
    while(*a++ = *b++);
}

int mystrcmp(const char *a, const char *b){
    while(*a && *a == *b) ++a, ++b;
    return *a - *b;
}

typedef struct st {
    int index;
    char name[21];
    struct st *next;
} Poketmon;

Poketmon HASH_TABLE[MAX_TABLE]; // 포켓몬 -> 숫자
Poketmon POOL [100000 + 5000];
int pcnt;

Poketmon ARR[100000 + 5000]; // 숫자 -> 포켓몬


int change (char *str){
    int i, len;
    int sum, mul;

    sum = 0, mul = 1;

    for(i = 0 ; str[i]; i++);
    len = i;

    for(i = len - 1 ; i>= 0 ; i--){
        sum += (str[i] - '0') * mul;
        mul *= 10;
    }
    return sum;
}

int main(){

    char str[21];

    scanf("%d %d", &N, &M);

    for(int i = 1 ; i<= N ; i++){
        scanf("%s", str);

        ull h = hash(str); // hash값
        Poketmon *nd = &POOL[pcnt++];

        nd->index = i; // 인덱스 저장해줌
        mystrcpy(nd->name, str); // 이름 저장해줌

        nd->next = HASH_TABLE[h].next;
        HASH_TABLE[h].next = nd;

        mystrcpy(ARR[i].name, str); // 순서대로 저장
    }

    for(int i = 0 ; i < M ; i++){
        scanf("%s", str);

        // 숫자 -> 이름: ARR
        if('0' < str[0] && str[0] <= '9'){

            int index = change(str);

            printf("%s\n", ARR[index].name); // ARR에 순서대로 저장했기 때문에 그대로 출력
        }
        // 이름 -> 숫자: HASH_TABLE
        else {
            ull h = hash(str);
            Poketmon *nd = HASH_TABLE[h].next;

            while(nd){
                // 0이면 같은 문자열
                if(!mystrcmp(nd->name, str)){
                    printf("%d\n", nd->index);
                    break;
                }
                nd = nd->next;
            }
        }
    }
    return 0;

}