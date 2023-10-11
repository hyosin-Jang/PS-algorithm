#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// 14% 시간초과 - 3중 for문 > 상어 이동하는 부분 개선
// s가 좌우를 왔다갔다하거나 상하를 왔다갔다 하므로, 행, 열을 가지고 나머지 같은 값으로 계산하도록 수정

int R, C, M; // 격자판 크기, 상어 수
int r, c, s, d, z; // 상어 위치, 속력, 이동방향, 크기
int dx[] = {0, -1, 1, 0, 0}; // 1부터 시작 위 아래 오른쪽 왼쪽
int dy[] = {0, 0, 0, 1, -1};

int answer = 0 ;// 낚시왕이 잡은 상어 크기 합

struct Shark {
    int s, d, z; // 스피드, 이동 방향, 크기
};

struct compare{
    bool operator()(Shark & s1 , Shark & s2){
        return s1.z < s2.z;
    }
};

struct Cell {
    priority_queue<Shark, vector<Shark>, compare> sharkes;
};

Cell map[102][102];

// cur_c열에 있는 상어 중 땅과 가장 가까운 상어 잡는다.
void grabShark(int cur_c){
    for(int i = 1 ; i <= R ; i++){
        if(map[i][cur_c].sharkes.size() > 0){
            answer += map[i][cur_c].sharkes.top().z;
            // 2. 상어잡으면 격자판에서 사라진다.
            map[i][cur_c].sharkes.pop();
            break;
        }
    }
}

// 3. 상어가 이동한다.
void moveShark(){
    // 3-1. 2중 for문 위에서 차례로 이동
    Cell temp_map[102][102]; // 이동 결과 담을 map

    for(
        int i = 1 ; i <=R ; i++){
            for(int j = 1 ; j<= C ; j++){
                if(map[i][j].sharkes.size() > 0){
                    Shark cur_shark = map[i][j].sharkes.top();
                    int nx = i, ny = j; // 현재 위치

                    for(int speed = 0 ; speed < cur_shark.s ; speed++){
                        nx = nx + dx[cur_shark.d];
                        ny = ny + dy[cur_shark.d];

                        // 경계 초과 시 방향 전환
                        if(nx < 1 || ny < 1 || nx > R || ny > C){
                            switch(cur_shark.d){
                                case 1:
                                    cur_shark.d = 2;
                                    break;
                                case 2:
                                    cur_shark.d = 1;
                                    break;
                                case 3:
                                    cur_shark.d = 4;
                                    break;
                                case 4:
                                    cur_shark.d = 3;
                                    break;
                            }
                            nx = nx + dx[cur_shark.d] * 2;
                            ny = ny + dy[cur_shark.d] * 2;
                        }
                    }
                    temp_map[nx][ny].sharkes.push({cur_shark.s, cur_shark.d, cur_shark.z});
                }
            }
        }

    // 3-2. 같은 칸에 두 마리 이상 존재하면 크기가 가장 큰 상어가 나머지 모두 잡아먹는다.
    for(int i = 1 ; i<=R ; i++){
        for(int j = 1 ; j<=C ; j++){
            int shark_num = temp_map[i][j].sharkes.size();
        
            while(!map[i][j].sharkes.empty()){
                map[i][j].sharkes.pop();
            }
            // 한 마리 있어도, 2마리 이상 있어도 제일 위에 있는 것 하나 꺼내는 건 동일함
            if(shark_num >= 1){
                Shark biggest_shark = temp_map[i][j].sharkes.top();
                map[i][j].sharkes.push(biggest_shark);
            }
        }
    }
}

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C >> M;

    if(M == 0){
        cout << "0\n";
        return 0;
    }

    for(int i = 0 ; i < M ; i++){
        cin >> r >> c >> s >> d >> z;
        if(d == 1 || d == 2){
            s = s % ((R-1) * 2);
        }
        else if (d == 3 || d==4){
            s = s % ((C-1) * 2);
        }
        map[r][c].sharkes.push({s, d, z});
    }

    int cur_c = 0; // 현재 열의 위치
    while(++cur_c <= C){
        // 1. cur_c 열에 있는 상어 중 땅과 가장 가까운 상어 잡는다.
        grabShark(cur_c);
        // 3. 상어가 이동한다.
        moveShark();
    }

    cout << answer << "\n";


    return 0;
}