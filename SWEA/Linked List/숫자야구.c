#include <stdio.h>

#define N 4

typedef struct st{
    int g[4];
    struct st* next;
} Node;

typedef struct {
    int strike, ball;
} Result;

Node HEAD;
Node POOL[10000];
int pcnt;

int visit[10];
int list[4];

// API
extern Result query(int guess[]);

/** 정답 후보군을 만드는 함수 */
void DFS(int L){
    if(L > 3){
        Node *nd = &POOL[pcnt++];

        // 4개의 숫자를 모두 구했으므로 linked list g[4]에 저장
        for(int k = 0 ; k < 4 ; k++) nd->g[k] = list[k];

        nd->next= HEAD.next;
        HEAD.next = nd;

        return;
    }

    for(int i = 0 ; i < 10 ; i++){
        if(visit[i]) continue;

        list[L] = i;
        visit[i] = 1;
        DFS(L + 1);
        visit[i] = 0;
    }
}

Result query2(int guess[], int list[]){
    Result result;
    int check[10] = {0};

    result.strike = 0;
    result.ball = 0;

    for(int i = 0 ; i < 4 ; i++) check[guess[i]]++;

    for(int idx = 0 ; idx < N ; ++idx){
        // 스트라이크인지 검사
        if(guess[idx] == list[idx]){
            result.strike++;
        
        // 볼인지 검사
        } else if (check[list[idx]] > 0){
            result.ball++;
        }
    }
    return result; 
}

void deleteNode(int stk, int ball, int guess[]){

    Node *nd = &HEAD;

    while(nd->next){

        Result result;
        int tmpstk, tmpball;

        // 삭제할 때 사용
        result = query2(guess, nd->next->g);
        tmpstk = result.strike;
        tmpball = result.ball;

        /** 스트라이크, 볼 개수가 모두 틀릴 경우 삭제 */
        if(!(tmpstk == stk && tmpball == ball)){
            nd->next= nd->next->next;
        } else {
            nd = nd->next;
        }
    }
}

void doUserImplementation(int guess[]){

    Result result;

    pcnt = 0;
    HEAD.next = 0;

    // 정답 후보군 생성
    DFS(0);

    while(1){
        int stk, ball;

        // 정답 후보군 1개를 guess에 복사
        for(int i = 0 ; i < 4 ; i++) guess[i] = HEAD.next->g[i];

        // 후보군 1개는 다시 볼 필요가 없으므로 head 이동
        HEAD.next = HEAD.next -> next;

        // 처음에 던진 답은 외부함수 query를 사용
        result = query(guess);

        // 정답 스트라이크, 정답 볼
        stk = result.strike;
        ball = result.ball;

        if(stk == 4) break;

        deleteNode(stk, ball, guess);

    }

}


int main(){



    return 0;
}