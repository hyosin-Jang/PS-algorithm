#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 7

typedef struct {
    int key;
} element;

struct list {
    element item;
    struct list * link;
};

// hash table은 ListNode 구조체를 가리키는 포인터 배열로 이루어져 있다.
struct list *hash_table[TABLE_SIZE];


// 제산 함수를 이용한 해싱 함수
int hash_function(int key){
    return key % TABLE_SIZE;
}

// 키가 버킷으로 들어오면 동적 메모리 할당을 이용해서 연결리스트 노드를 생성한다.
void hash_chain_add(element item, struct list *ht[]){
    int hash_value = hash_function(item.key);

    // 새로운 노드 연결할 포인터
    struct list *ptr;

    // node 포인터가 NULL이 되면 루프 탐색이 끝나는데, NULL 바로 앞에 포인터가 필요하므로 node_before로 같이 움직여줌. 
    struct list *node_before = NULL, *node = ht[hash_value];

    // 버킷에 연결된 기존 연결 리스트에서 동일한 키가 있는지 검사한다.
    for(; node ; node_before = node, node = node->link){
        // - 동일한 키가 발견되면 오류 메시지를 출력한다. 
        if(node->item.key == item.key){
            fprintf(stderr, "이미 탐색키가 저장되어 있음\n");
            return;
        }
    }

    ptr = (struct list *)malloc(sizeof(struct list));
    ptr->item = item;
    ptr->link = NULL;

    // - 동일키가 없으면 연결리스트 맨 끝에 새로운 키를 포함하는 새로운 노드를 연결한다.
    if(node_before){
        node_before->link = ptr;
    } else {
    // - 만약 기존 연결리스트가 없으면 해시테이블 포인터에 새로운 노드를 연결한다.
        ht[hash_value] = ptr;
    }
}


/** 체인법을 사용하여 테이블에 저장된 키를 탐색 */
void hash_chain_search(element item, struct list *ht[]){
    struct list *node;

    int hash_value = hash_function(item.key);
    
    for(node = ht[hash_value] ; node ; node = node->link){
        if(node->item.key == item.key){
            fprintf(stderr, "탐색 %d 성공\n", item.key);
            return;
        }
    }
    printf("키를 찾지 못했음\n");
}

/** 해싱 테이블의 내용 출력 */
void hash_chain_print(struct list *ht[]){
    struct list *node;
    int i;
    printf("===================\n");
    for(i = 0 ; i < TABLE_SIZE ; i++){
        printf("[%d] -> ", i);
        for(node = ht[i]; node ; node = node->link){
            printf("%d->", node->item.key);
        }
        printf("\n");
    }
    printf("===================\n");
}


#define SIZE 5

int main(){

    int data[SIZE] = {8, 1, 9, 6, 13};
    element e;

    for(int i = 0 ; i<SIZE ; i++){
        e.key = data[i];
        hash_chain_add(e, hash_table);
        hash_chain_print(hash_table);
    }
    for(int i = 0 ; i < SIZE ; i++){
        e.key = data[i];
        hash_chain_search(e, hash_table);
    }

    return 0;
}