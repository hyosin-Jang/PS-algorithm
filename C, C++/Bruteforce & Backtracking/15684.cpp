#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 53분 solve
// 9% 시간초과 => dfs 재귀 수행할 때, 이전 단계에서 r행, c열 탐색 중이므로 다음 단계도 r행부터 검사

int N, M, H, a, b; // 세로 선, 가로 선, 놓을 수 있는 가로 위치 개수

int map[31][11] = {0};
bool finish = false;

// 사다리 실행했을 때 자기 자신 나오는지 검사
string answer = "";

int min_ladder = 1e9;
bool run(){

    string temp = answer;

    for(int i = 1 ; i <= H ; i++){
        for(int j = 1 ; j <= N -1 ; j++){
            if(map[i][j]) swap(temp[j], temp[j+1]);
        }
    }
    return answer == temp ? true : false;
}

void dfs(int r, int c, int cnt){
    // i,j 위치에 사다리 설치 후 다음 스텝으로 넘어옴
    if(cnt >= min_ladder) return;
    if(run()){
        min_ladder = min(min_ladder, cnt);
        finish = true;
        return;
    }

    if(cnt == 3) return;

    for(int i = r ; i <= H ; i++){
        for(int j = 1 ; j <= N -1 ; j++){
            if(map[i][j] == 0 && map[i][j-1] == 0 && map[i][j+1] == 0){
                map[i][j] = 1;
                dfs(i, j, cnt + 1);
                map[i][j] = 0; // 백트래킹
            }
        }
    }
}

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> H;
    if(M == 0) {
        cout << "0\n";
        return 0;
    }

    for(int i = 1 ; i <= N ; i++){
        answer += to_string(i);
    }

    for(int i = 0 ; i < M ; i++){
        cin >> a >> b;
        map[a][b] = 1;
    }

    if(run()){
        cout << "0\n";
        return 0;
    }

    for(int i = 1 ; i <= H ; i++){
        for(int j = 1 ; j <= N -1 ; j++){
            // 사다리 놓을 수 있는 경우 dfs 탐색 시작
            if(map[i][j] == 0 && map[i][j-1] == 0 && map[i][j+1] == 0){
                map[i][j] = 1;
                dfs(i, j, 1);
                map[i][j] = 0;
            }
        }
    }
    if(finish){
        cout << min_ladder << "\n";
    } else cout << "-1\n";

    return 0;
}