#include <iostream>
#include <vector>
using namespace std;

int dice[5][4] = {0}; // 주사위
int board[21][21] = {0}; // 지도

pair<int, int> board_dice; // 지도상 주사위 위치
int N, M, X, Y, K;
vector<int> op(1001, 0); // 명령

int dx[4] = {0, 0, -1, 1}; // 동, 서, 북, 남
int dy[4] = {1, -1, 0, 0}; 

// 주사위 평면 도형 갱신하는 함수
void move_dice(int dir){
    if(dir == 1){
        // fix: 동쪽일때 수정
        int temp = dice[1][0];
        dice[1][0] = dice[1][1];
        dice[1][1] = dice[1][2];
        dice[1][2] = dice[3][1];
        dice[3][1] = temp; 
    } else if (dir == 2){
        int temp = dice[1][2];
        dice[1][2] = dice[1][1];
        dice[1][1] = dice[1][0];
        dice[1][0] = dice[3][1];
        dice[3][1] = temp;
    } 
    else if (dir == 3){
        int temp = dice[3][1];
        dice[3][1] = dice[2][1];
        dice[2][1] = dice[1][1];
        dice[1][1] = dice[0][1];
        dice[0][1] = temp;
    } else {
        int temp = dice[0][1];
        dice[0][1] = dice[1][1];
        dice[1][1] = dice[2][1];
        dice[2][1] = dice[3][1];
        dice[3][1] = temp;
    }
}

void print_dice(){
    for(int i = 0 ; i< 4 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            cout << dice[i][j] << " ";
        }
        cout << "\n";
    }
    cout <<"\n\n-------출력 끝-------\n\n";
}

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> X >> Y >> K;

    for(int i = 0 ; i < N ;i++){
        for(int j = 0 ; j< M ; j++){
            cin >> board[i][j];
        }
    }

    for(int i = 0 ; i < K ; i++){
        cin >> op[i];
    }

    int cx = X;
    int cy = Y;

    for(int i = 0 ; i < K ; i++){
        int nx = cx + dx[op[i] - 1];
        int ny = cy + dy[op[i] - 1];
        if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

        // 2-3. 지도에서 dice 위치 갱신
        cx = nx;
        cy = ny;

        // 2-3. move로 주사위 그래프 갱신
        move_dice(op[i]);


        // 2-4. 바닥칸 숫자 비교 후 갱신
        if(board[cx][cy] == 0){
            board[cx][cy] = dice[1][1];
        } else { 
            // 0이 아니면 칸에 쓰인 숫자가 주사위 바닥면으로 복사
            // 칸에 쓰여 있는 수는 0이 된다!
            dice[1][1] = board[cx][cy];
            board[cx][cy] = 0;
        }

        //print_dice();

        // 2-5. 상단에 쓰인 숫자 출력
        cout << dice[3][1] << "\n";
    }

    // <문제 풀이>
    // 1. dice 2차원 배열 구현, 지도에서 dice위치, dice에서 현재 위치(밑면), 윗칸(윗면) 기록하는 pair<int,int>
    // 2. 명령 반복문 돌면서
    //   2-1. 지도에서 dice위치에 다음 방향 갈 수 있는지 검사
    //   2-2. 바깥으로 이동할 수 없으면, 해당 명령 무시 continue. (다음으로 넘어가기)
    //   2-3. 이동할 수 있으면, 지도에서 dice위치 갱신, dice 2차원 배열에서 이동 방향으로 주사위 위치 갱신 (윗면, 밑면 갱신)
    //      - 윗면, 밑면 갱신할 때, j=0, j=1, j=2에 따라 갱신 방법이 다름
    //      - J=0 => i=1, j=0 (상, 하, 좌, 우)가 오른쪽 칸이 될 수도 있고, 위 아래 칸이 될 수도 있네 => 로직 다시 생각!
    //   2-4. 해당 칸의 지도 숫자가 0이면 주사위 밑면 숫자를 지도상 dice 위치에 복사
    //        - 0이 아니면 칸에 쓰여있는 수를 주사위 바닥면에 넣기 + 칸에 쓰여 있는 수는 0이 된다! (조건 누락해서 1트 실패)
    //   2-5. 상단에 쓰여있는 숫자 출력

    

    return 0;
}