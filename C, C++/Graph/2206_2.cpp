#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 1001

int N, M;
int graph[MAX][MAX];
int dist[MAX][MAX];
int visited[MAX][MAX][2]; // 마지막 축 - 0: 벽 안 깬 상태, 1: 깬 상태

int dx[4] = {0, 0, 1, -1};
int dy[4] = { 1, -1, 0, 0};

struct cell {
    int x, y, wall; // 벽 부순 개수
};

void bfs(){
    queue<cell> q;
    q.push({0,0,0});
    dist[0][0] = 1;
    visited[0][0][0] = 1;

    while(!q.empty()){
        cell cur = q.front();
        q.pop();

        if(cur.x == N-1 && cur.y == M-1) {
            cout << dist[N-1][M-1] << "\n";
            return;
        }

        for(int i = 0 ; i < 4 ; i++){
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

            // 벽인 곳을 방문하려면 현재 깬 벽의 개수가 0이여야 함
            if(graph[nx][ny] == 1 && cur.wall == 0){
                dist[nx][ny] = dist[cur.x][cur.y] + 1;
                q.push({nx, ny, cur.wall + 1});
            }
            if(graph[nx][ny] == 0 && visited[nx][ny][cur.wall] == 0){
                visited[nx][ny][cur.wall] = 1; // 방문 표시
                dist[nx][ny] = dist[cur.x][cur.y] + 1;
                q.push({nx, ny, cur.wall});
            }
        }
    }
    cout << "-1\n";
    return;

}
int main(void){

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    string tmp;
    for(int i = 0 ; i < N ; i++){
        cin >> tmp;
        for(int j = 0 ; j< M ; j++){
            graph[i][j] = tmp[j] - '0';
        }
    }

    bfs();
    
    return 0;
}