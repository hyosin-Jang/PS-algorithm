#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

// BFS + 다익스트라 사용하는 문제
// 다익스트라 알고리즘을 이용하되, 기준을 꺾은 개수로 표현한다.
#define MAX_VALUE 987654321
#define MAX 101
int W, H;
int dp[MAX][MAX];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

char board[MAX][MAX];
vector<pair<int, int>> c;

void bfs(){
    priority_queue<pair<pair<int, int>, pair<int, int>>> pq;
    int first_row = c[0].first;
    int first_col = c[0].second;

    // 시작 점 기준 네 방향 넣어주기
    for(int i = 0 ; i < 4 ; i++){
        int next_row = first_row + dy[i];
        int next_col = first_col + dx[i];

        if(next_row <0 || next_col < 0 || next_row >= H || next_col >= W) continue;
        if(board[next_row][next_col] == '*') continue;

        pq.push({{0, i}, {next_row, next_col}}); // 최단경로 대신 사용한 거울 개수 (꺾은 방향 개수)를 기준으로 삼음
        dp[next_row][next_col] = 0;
    }

    while(!pq.empty()){
        int now_row = pq.top().second.first;
        int now_col = pq.top().second.second;
        int now_cnt = -pq.top().first.first;
        int now_dir = pq.top().first.second;
        pq.pop();

        if(dp[now_row][now_col] < now_cnt) continue; // 최솟값인 경우만 방문
        if(now_row == c[1].first && now_col == c[1].second) continue; // 도착한 경우 패스

        for(int i = 0 ; i < 4; i++){
            if(i == (now_dir + 2) % 4) continue; // 같은 방향인 경우 패스

            int next_row = now_row + dy[i];
            int next_col = now_col + dx[i];
            int next_cnt = i == now_dir ? now_cnt : now_cnt + 1;
            int next_dir = i;

            if(next_row < 0 || next_col < 0 || next_row >= H || next_col >= W) continue;
            if(board[next_row][next_col] == '*') continue;

            if(dp[next_row][next_col] >= next_cnt){
                dp[next_row][next_col] = next_cnt;
                // 거울 적게 쓴게 우선순위가 높아야하므로 min_heap으로 구현 or 음수값 넣기
                pq.push({{ -next_cnt, next_dir }, {next_row, next_col }});
            }
        }
    }
}


int main(void){

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> W >> H;

    for(int i = 0 ; i < H ; i++){
        for(int j = 0 ; j < W ; j++){
            cin >> board[i][j];
            if(board[i][j] == 'C') c.push_back({i, j});
            dp[i][j] = MAX_VALUE; // 최댓값으로 초기화
        }
    }

    dp[c[0].first][c[0].second] = 0; // 사용한 거울 개수

    bfs();

    cout << dp[c[1].first][c[1].second] << "\n";

    return 0;
}