#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int road1[101][101];
int road2[101][101];
int N, L;
int cnt = 0;

void passCnt(int road[][101]){
    // 가로 확인
    for(int i = 0 ; i< N ; i++){
        // i번째 행에 대하여 매번 slope를 검사하므로 slope[h] = 1
        // 이라는 것은 h번째 cell에 경사로를 설치했다는 것을 의미한다.
        // 행마다 새로 갱신해서 세어준다.
        bool slope[101] = {0}; // 경사로 여부
        bool possible = true; // 가능한 길인지 확인

        // i 번째 가로 길에 대하여 각 칸을 검사
        for(int h = 0 ; h < N-1 ; h++){
            // 1. 높이 차가 1보다 크면 불가능한 길
            if(abs(road[i][h] - road[i][h+1]) > 1){
                possible = false;
                break;
            }

            // 2. 경사로를 위에서 아래로 설치할 때 - 지나갈 길에 설치
            if(road[i][h] == road[i][h+1] + 1){
                int cur_height = road[i][h+1];
                // L만큼의 여유가 있는지 확인
                for(int k = h + 2 ; k < h+1 + L ; k++){
                    if(k >=N || road[i][k] != cur_height){
                        possible = false;
                        break;
                    }
                }
                if(possible){
                    // 경사로 설치 후 표시
                    slope[h + L] = true;
                } else break;
            }
            // 3. 경사로를 아래에서 위로 설치할 때 - 지나온 길에 설치
            if(road[i][h] == road[i][h+1] - 1){
                int cur_height = road[i][h];
                for(int k = h ; k > h - L ; k--){
                    if(k < 0 || road[i][k] != cur_height || slope[k]){
                        possible = false;
                        break;
                    }
                }
                if(!possible) break;
            }
        }
        if(possible) cnt++;
    }
}

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> L;
    for(int i = 0 ; i< N ; i++){
        for(int j = 0 ; j <N ; j++){
            cin >> road1[i][j]; // 가로로 가는 길 확인
            road2[j][i] = road1[i][j]; // 세로로 가는 길 확인
        }
    }
    passCnt(road1); // 가로로 가는 길 개수
    passCnt(road2); // 세로로 가는 길 개수
    cout << cnt << "\n";

    return 0;
}

// 다음 좌표 높이를 보고 3가지 경우로 나눌 수 있다.
// 1. 다음 좌표 높이 차가 1보다 더 크게 날 때, 이미 길이 될 수 없으므로 이 행은 pass
// 2. 다음 좌표가 1만큼 작아 지나갈 길에 경사로를 설치할 때
//   2-1. 지나갈 좌표 중 L만큼의 길이 같은 높이로 이루어져 있는지 검사
//   2-2. 위 조건을 만족하지 않으면 경사로 설치 불가능
//   2-3. 만족하면 경사로가 설치된 마지막 좌표에 경사로가 설치되었다고 표시 -> 경사로 겹치는 것 막기
// 3. 다음 좌표가 1만큼 커서 지나온 길에 경사로 설치할 때
//   3-1. 지나온 좌표를 확인해서 L만큼 같은 높이로 이루어져 있는지 확인
//   3-2. 이 부분에서는 지나온 길에 경사로가 설치되었는지 꼭 확인하기
//   3-3. 불가능하면 경사로 설치 불가능 