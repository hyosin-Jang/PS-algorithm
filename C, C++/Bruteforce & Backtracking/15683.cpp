#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;


int N, M;
int visited[5][5] = {0};
vector<tuple<int, int, int>> cctv; // type, x, y
vector<vector<int>> graph(9, vector<int>(9, 0));

int min_cnt = 1e9;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void check(int x, int y, int dir){
    dir %= 4; // 4 초과할 수 있으므로 4로 나눈 나머지 사용하기

    while(1){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        x = nx;
        y = ny;

        if(nx < 0 || nx >= N || ny < 0 || ny >= M) return;
        if(graph[nx][ny] == 6) return;
        if(graph[nx][ny] >= 1 && graph[nx][ny] <= 5) continue; // cctv가 놓인 경우 패스
        graph[nx][ny] = -1;
    }
}

void solve(int idx){
    if(idx == cctv.size()){ 
        // cctv모두 탐색한 경우 사각지대 개수 구하기
        int cnt = 0 ;
        for(int i = 0 ; i< N ; i++){
            for(int j = 0 ; j< M ; j++){
                if(!graph[i][j]) cnt++;
            }
        }
        min_cnt = min(min_cnt, cnt);
        return;
    }
    
    tuple<int, int, int> cur = cctv[idx];
    int x = get<1>(cur);
    int y = get<2>(cur);
    int temp[9][9];

    for(int dir = 0 ; dir < 4; dir++){
        for(int i = 0 ; i< N ; i++){
            for(int j = 0 ; j< M ; j++){
                temp[i][j] = graph[i][j]; // 백ㄴ업
            }
        }
        // cctv type에 따라 감시구역 표시
        switch(get<0>(cur)){
            case 1:
                check(x, y, dir);
                break;
            case 2:
                check(x, y, dir);
                check(x, y, dir + 2);
                break;
            case 3:
                check(x, y, dir);
                check(x, y, dir + 1);
                break;
            case 4:
                check(x, y, dir);
                check(x, y, dir + 1);
                check(x, y, dir + 2);
                break;
            case 5:
                check(x, y, dir);
                check(x, y, dir + 1);
                check(x, y, dir + 2);
                check(x, y, dir + 3);
        }
        solve(idx + 1); // 다음 cctv 탐색

        // 탐색 끝나고 나면 다음 방향을 위해 돌려놓기
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j< M ; j++){
                graph[i][j] = temp[i][j];
            }
        }
    }
}

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> N >> M;

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            cin >> graph[i][j];
            if(graph[i][j] >= 1 && graph[i][j] <= 5){
                cctv.push_back(make_tuple(graph[i][j], i, j));      
            }
        }
    }

    solve(0);

    cout << min_cnt << "\n";

    return 0;
}