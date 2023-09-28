#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define MAX 51
int N, M;
int total_virus = 0;

vector<vector<int>>board(MAX, vector<int>(MAX, 0));
vector<pair<int, int>> virus;

// 30분 2트 solve
// 18% 틀린 이유: 바이러스와 빈칸을 모두 0으로 표시한 경우
// 바이러스를 놓은 빈칸이면 이미 바이러스가 놓여있으므로 확산시킬 필요 없이 바로 종료되는데 
// 빈칸이랑 구분하지 못했음 => 빈칸은 -2, 바이러스를 놓은 빈칸은 0으로 표기하는 방식으로 해결

int total_min_time = 1e9;
int invalid_flag = true;

int visited[11] = {0};
int dx[4] = {0, 0 , -1, 1};
int dy[4] = {1, -1, 0, 0};

int spread_virus(){
    // 체크된 인덱스가 0

    int finish_time = 0;
 
    queue <pair<int, int>> q;
    vector<vector<int>> copy(N + 1, vector<int> (N +1, 0));

    for(int i = 0 ; i< N; i++){
        for(int j = 0 ; j <N ; j++){
            if(board[i][j] == 1) copy[i][j] = -1;
            else copy[i][j] = -2; // 빈칸 -2 표시
        }
    }

    for(int i = 0 ; i < total_virus; i++){
        if(visited[i] == 1){ 
            int x = virus[i].first;
            int y = virus[i].second;
            q.push({x, y});
            copy[x][y] = 0; // 바이러스가 놓인 곳 0 표시
        }
    }

    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();

        for(int i =0 ; i <4 ; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || nx >= N || ny < 0 || ny >= N || copy[nx][ny] == -1 || copy[nx][ny] == 0)
                continue;
            
            if(copy[nx][ny] == -2){
                copy[nx][ny] = copy[cur.first][cur.second] + 1;
                q.push({nx, ny});

                if(finish_time >= total_min_time) return finish_time; // 바로 종료
            }
        }
    }

    int zero_count = 0;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j< N ; j++){
            if(copy[i][j] != -1 && copy[i][j] > finish_time) finish_time = copy[i][j];
            if(copy[i][j] == -2) zero_count++;
        }
    }
    if(zero_count > 0) return -1;
    return finish_time;
}

// total_virus 개수 중 M개 선택
void dfs(int idx, int cnt){
    // M개를 선택한 경우 바이러스 확산 시간 계산
    if(cnt == M){
        int finish_time = spread_virus();
        if(finish_time != -1) {
            invalid_flag = false;
            total_min_time = min(finish_time, total_min_time);
        }
        return;
    }
    for(int i = idx ; i < total_virus ; i++){
        if(visited[i] == 0){
            visited[i] = 1;
            dfs(i + 1, cnt + 1);
            visited[i] = 0;
        }
    }
}

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;


    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cin >> board[i][j];
            if(board[i][j] == 2){
                virus.push_back({i, j});
                total_virus++;
            }
        }
    }

    dfs(0, 0);

    if(invalid_flag) cout << "-1\n";
    else cout << total_min_time << "\n";
    return 0;
}