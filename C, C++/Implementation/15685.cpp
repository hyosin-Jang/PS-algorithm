#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, x, y, d, g;
int cnt = 0;
int visited[101][101] = {0};
int graph[101][101] = {0}; // 0 ~ 100만 유효한 좌표

struct coord {
    int y;
    int x;
    int d; // 회전 방향
};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1}; // 0, 1, 2, 3 순서

void solve(int x, int y, int d, int g){
    vector<coord> v;

    // d: 현재 좌표에서 d 방향으로 갱신해서 다음 좌표 (y+dy[d], x+dx[d])가 만들어졌다는 뜻
    v.push_back({y + dy[d], x + dx[d], d});

    for(int i = 1 ; i <= g ; i++){
        // 큐에 있는 좌표들을 마지막 좌표 기준으로 90도 시계방향 돌리기 - 유효 좌표 확인 (필드 초과 범위는 입력으로 주어지지 않음)
        coord cur = v[v.size() - 1];
        int curX = cur.x;
        int curY = cur.y;
        
        for(int j = v.size() -1 ; j >=0 ; j--){
            // next는 각각의 값이 필요하고, 좌표는 마지막 좌표를 기준으로 갱신되는 좌표가 필요함
            // 갱신되는 좌표는 현재 좌표가 생성된 방향을 시계 방향으로 90도 돌린 방향의 반대 방향이므로
            // 반시계 방향임 => 따라서 (dir + 1) % 4가 됨 
            int next = (v[j].d + 1) % 4; 
            curX = curX + dx[next];
            curY = curY + dy[next];
            v.push_back({curY, curX, next});
        }
    }


    // 시작점 방문 표시
    visited[y][x] = 1;
    for(int i = 0 ; i < v.size() ; i++){
        coord cur = v[i];
        visited[cur.y][cur.x] = 1;
    }
}
int main(void){

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0 ; i<N ; i++){
        cin >> x >> y >> d >> g;
        solve(x, y, d, g);
    }
    for(int i = 0 ; i <= 99 ; i++){
        for(int j = 0 ; j <= 99 ; j++){
            if(visited[i][j] == 1 && visited[i+1][j] == 1 && visited[i][j+1] == 1 && visited[i+1][j+1]==1){
                cnt++;
            }
        }
    }
    cout << cnt << "\n";

    return 0;
}

    // 1. 입력
    // 2. 각 명령어 돌면서 수행
    // 2-1. 시작점 큐에 넣고, 시작 방향을 통해서 0세대 넣기
    // 2-2. 0~g세대까지 반복문 돌면서,
    //     - 마지막 점을 기준으로 앞에 있는 것은 역순으로 90도 시계방향 회전해서 큐에 뒤에 넣어주기
    // 2-3. 회전 끝나면, 큐에 들어 있는 좌표들은 visited 1 표시
    // 3. 모든 명령어 수행 끝나면 각점에 대해 4군데가 모두 visited 1이면 count++