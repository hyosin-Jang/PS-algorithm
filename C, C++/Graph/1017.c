#include <stdio.h>

int K, V, E;

typedef struct st {
    int node;
    struct st* next;
} Node;

#define MAX_SIZE 20200

Node HEAD[MAX_SIZE];
//Node POOL[202000 * 2]; 메모리풀 관련 코드 삭제
// int pcnt;

int check[MAX_SIZE];

void init(){
    /** 메모리 풀 초기화 */
    // pcnt = 0; 

    for(int i = 1 ; i<= V ; i++) HEAD[i].next = 0, check[i] = 0;
}

void make(int p, int c){
    // Node *nd = &POOL[pcnt++];
    Node *nd = (Node*)malloc(sizeof(Node));
    
    nd -> node = c;
    nd -> next = HEAD[p].next;
    HEAD[p].next = nd;
}

int DFS(int node, int color){
    check[node] = color;

    for(Node *p = HEAD[node].next; p ; p = p->next){
        // 인접 노드가 같은 색상인 경우
        if(check[p->node] == color) return 0;
        if(!check[p->node]){
            // 인접 노드를 반대 색상으로 칠하고 재귀 탐색한다.
            if(!DFS(p->node, 3 - color)) return 0;
        }
    }
    return 1;
}

int main(){
    scanf("%d", &K);

    for(int tc = 1 ; tc <= K ; tc++){
        int flag;
        scanf("%d %d", &V, &E);

        init();

        for(int i = 0 ; i < E ; i++){
            int p, c;
            scanf("%d %d", &p ,&c);
            make(p, c);
            make(c, p);
        }

        flag = 0;

        // 그래프가 끊어져있을 수 있으므로 모든 정점을 탐색한다.
        for(int i = 1 ; i<= V ; i++){
            if(!check[i]){
                flag = DFS(i, 1);
                if(!flag) break;
            }
        }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}