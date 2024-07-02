#include <stdio.h>


typedef struct st {
    int node;
    struct st * next;
} Node;

/**
 * 삽입 노드의 순서를 지켜야할 때는 TAIL을 사용한다.
 * 하지만 make에서 매번 if, else 문을 체크해야 하기 때문에
 * HEAD만 사용했을 때보다 성능이 떨어짐.
*/

Node HEAD[110], TAIL[110];
Node POOL[110 * 110];
int check[110];

int pcnt = 0;
int N, L, p, c;
int answer = 0;

void init(){
    pcnt = 0;

    /** 정점의 개수가 N */
    for(int i = 1 ; i<= N ; i++){
        HEAD[i].next = 0; TAIL[i].next = 0; check[i] = 0;
    }

    answer = 0 ;
}

void make(int p, int c){
    Node *nd = &POOL[pcnt++];
    nd->node = c;

    /** p의 인접 노드가 한개도 없는 경우 (신규 노드 삽입) */
    if(HEAD[p].next == NULL && TAIL[p].next == NULL){
        HEAD[p].next = TAIL[p].next = nd;
    } else {
        TAIL[p].next -> next = nd;
        TAIL[p].next = nd;
    }
}

void DFS(int p){

    for(Node * nd = HEAD[p].next ; nd ; nd = nd -> next){
        if(!check[nd->node]){
            check[nd->node] = 1;
            answer++;
            DFS(nd->node);
        }
    }
}

int main(){

    scanf("%d", &N);

    init();
    scanf("%d", &L);

    while(L--){
       scanf("%d %d", &p, &c);
       make(p, c); 
       make(c, p); 
    }

    check[1] = 1; 
    DFS(1);

    printf("%d\n", answer);


    return 0;
}