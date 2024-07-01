#include <stdio.h>

int N, M, ANSWER;
typedef struct st {
    int node;
    struct st *next;
} Node;

Node HEAD[110];
Node POOL[110 * 110];
int pcnt;
int visit[110];

void init(int n){
    pcnt = 0;
    for(int i = 1 ; i<= N ; i++) HEAD[i].next = 0;
    for(int i = 1 ; i<= N ; i++) visit[i] = 0;

    ANSWER = 0;
}

void make(int p , int c){
    /* malloc 대신 POOL에서 메모리를 가져온다. */
    Node* nd = &POOL[pcnt++];
    nd -> node = c;
    /** HEAD와 바로 인접하게 연결한다. */
    nd->next = HEAD[p].next;
    HEAD[p].next = nd;
}

int queue[110 * 110];
int wp, rp;

void BFS(){
    int out;
    wp = rp = 0;

    /** 1번 노드부터 방문 시작 */
    queue[wp++] = 1;
    visit[1] = 1;

    while(wp > rp){
        out = queue[rp++];

        for(Node *p = HEAD[out].next ; p ; p = p->next){
            if(visit[p->node] == 0){
                visit[p->node] = 1;
                ANSWER++;
                queue[wp++] = p->node;
            }
        }
    }
}

void outputHead(int head){
    printf("head %d: ", head);

    for(Node *p = HEAD[head].next ; p ; p = p->next) printf("%d ", p->node);
    putchar('\n');
}

int main(){
    scanf("%d %d", &N, &M);

    init(N);

    for(int i = 0 ; i< M ; i++){
        int p, c;
        scanf("%d %d", &p, &c);

        // 양방향 연결
        make(p, c);
        make(c, p);
    }

    BFS();
    printf("%d\n", ANSWER);

    return 0;
}