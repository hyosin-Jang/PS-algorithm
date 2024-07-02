#include <stdio.h>

#define MAX 20000 + 200
typedef struct st {
    int node;
    struct st* next;
} Node;

Node HEAD[MAX];
Node POOL[202000 * 2]; /** 필요한 노드의 개수가 40만개 */

int pcnt = 0;
int K, V, E;
int check[MAX];

void init(){
    pcnt = 0;
    for(int i = 1 ; i<= V ; i++) HEAD[i].next = 0, check[i] = 0;
}

void make(int p, int c){
    Node *nd = &POOL[pcnt++];

    nd->node = c;

    nd->next = HEAD[p].next;
    HEAD[p].next = nd;
}

int DFS(int p, int color){
    /** 인접 노드들을 재귀적으로 탐색하면서 현재 노드와 반대 색상 칠해주기 */

    check[p] = color;

    for(Node *nd = HEAD[p].next ; nd ; nd = nd->next){
        // 인접 노드인데 현재 노드랑 색이 같으면 이분 그래프 조건 만족 X
        if(check[nd->node] == color){
            return 0;
        }
        // 방문하지 않은 경우 현재 색이랑 반대 색상으로 칠해본다.
        // 1 -> 2, 2 -> 1
        if(check[nd->node] == 0){
            if(!DFS(nd->node, 3 - color)) return 0;
        }
    }
    return 1;
}

int main(){

    scanf("%d", &K);

    while(K--){

        int flag = 0;
        scanf("%d %d", &V, &E);

        init();

        for(int i = 0 ; i < E ; i++){
            int p, c;

            scanf("%d %d", &p, &c);
            make(p, c);
            make(c, p);
        }

        for(int i = 1 ; i<= V ; i++){
            /** 안 칠했으면 색칠해보기 */
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