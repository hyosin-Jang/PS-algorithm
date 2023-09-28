#include <iostream>
#include <vector>
using namespace std;

int graph[1001][1001] = {0};
int N, M, X;
int a, b, c;

// 10분
// 전형적인 플로이드 와샬
int main(void){

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // 모든 학생은 이동 가능
    cin >> N >> M >> X;

    // 초기화
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j<= N ; j++){
            if(i==j) graph[i][j] = 0;
            else graph[i][j] = 1e9;
        }
    }

    // 단방향
    for(int i = 0 ; i < M ; i++){
        cin >> a >> b >> c;
        graph[a][b] = c;
    }

    for(int k = 1 ; k <= N ; k++){
        for(int i = 1 ; i <=N ; i++){
            for(int j =1 ; j<=N ; j++){
                if(i == j) continue;
                // k를 거쳐간게 더 소요 시간이 작은 경우
                if(graph[i][j] > graph[i][k] + graph[k][j]){
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }

    // 이동할 수 없는 경우는 주어지지 않음 - 고려 x
    int max_time = 0;

    // 양방향 갱신
    // 오고 가는데 걸리는 시간
    // i->X, X->i 합쳤을 때 가장 큰 학생의 소요시간 리턴
    for(int i = 1 ; i <=N ; i++){
       if(graph[i][X] + graph[X][i] > max_time){
            max_time = graph[i][X] + graph[X][i];
       }
    }
    cout << max_time << "\n";

    return 0;
}