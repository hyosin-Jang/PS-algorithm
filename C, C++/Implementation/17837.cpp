#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <algorithm>
using namespace std;

int N, K;

struct Horses {
    int x, y, dir, num; // 1 ~ K
};

deque<Horses> horses;

struct Cell {
    deque<Horses> horses;
    int color; // 0: 흰색, 1: 빨간색, 2: 파란색
};

Cell map[14][14];

int dx[] = {0, 0, 0, -1, 1};
int dy[] = {0, 1, -1, 0, 0};



int main(void){

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    int r, c, d;

    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= N ; j++){
            cin >> map[i][j].color;
        }
    }

    Horses dummy = {0, 0, 0, 0};

    horses.push_back(dummy); // 0번 인덱스 맞춰줌

    for(int i = 1 ; i <= K ; i++){
        cin >> r >> c >> d;
        map[r][c].horses.push_back({r,c, d, i});
        horses.push_back({r,c,d,i}); // 순서대로 기록되어 있음
    }

    int turn = 0;
    while(++turn <= 1000){
        // 한 턴에는 1~K번 말을 이동한다.
        for(int i = 1 ; i <= K ; i++){
            int next_dir = horses[i].dir;
            int cx = horses[i].x;
            int cy = horses[i].y;

            // 다음 칸이 체스판을 벗어나는 경우 && 파란색인 경우
            int nx = cx + dx[next_dir];
            int ny = cy + dy[next_dir];

            // 파란색이거나 경계나가면 방향 바꿔줌
            if(nx < 1 || ny < 1 || nx > N || ny > N || map[nx][ny].color == 2){
                int reverse_dir = 0;
                if(next_dir == 1) reverse_dir = 2;
                else if(next_dir == 2) reverse_dir = 1;
                else if(next_dir == 3) reverse_dir = 4;
                else if(next_dir == 4) reverse_dir = 3;

                horses[i].dir = reverse_dir; // 방향 바꾼 것 갱신 (위에 얹힌 말은 방향 전환 안함)

                nx = cx + dx[reverse_dir];
                ny = cy + dy[reverse_dir];
            }

            // 방향 바꾼 칸이 파란색이거나 경계를 벗어난다면 가만히 있는다.
            if(nx < 1 || ny < 1 || nx > N || ny > N || map[nx][ny].color == 2) continue;
            
            // i번 말이 놓여 있는 위치에서 위에 놓인 말들도 함께 이동한다.
            deque<Horses> temp = map[cx][cy].horses; // 현재 몇번째 있는지 확인

            // A번말이 이동하려는 칸이 흰색인 경우 - 그 칸에 위에 원래 순서대로 쌓인다.
            if (map[nx][ny].color == 0){
                // temp
                int last_num = temp.back().num;
                stack<Horses> temp_stack;

                while(last_num != i){
                    temp_stack.push(temp.back());
                    temp.pop_back(); // 뒤에서 빼고,
                    last_num = temp.back().num; // 마지막 갱신
                }
                // i는 바로 넣어주기 - i번째 좌표 업데이트
                map[nx][ny].horses.push_back(temp.back());
                temp.pop_back();
                horses[i].x = nx;
                horses[i].y = ny;

                // temp_stack에 있는 것 옮겨주기
                while(!temp_stack.empty()){
                    Horses last_horse = temp_stack.top();
                    temp_stack.pop();
                    map[nx][ny].horses.push_back(last_horse); // 뒤에다가 업데이트
                    horses[last_horse.num].x = nx; // 좌표 업데이트
                    horses[last_horse.num].y = ny;                    
                }
                map[cx][cy].horses = temp; // 업데이트

                // 턴 종료되는지 검사
                if(map[nx][ny].horses.size() >= 4){
                    cout << turn << "\n";
                    return 0;
                }                
            }


            // 빨간색인 경우
            else if (map[nx][ny].color == 1){
                // temp에서 뒤에서 pop하고 nx,ny 뒤에다 쌓으면서 num == i일 때까지 
                int last_num = temp.back().num;

                while(last_num != i){
                    map[nx][ny].horses.push_back(temp.back()); // 뒤에다가 업데이트
                    temp.pop_back();
                    horses[last_num].x = nx; // 좌표 업데이트
                    horses[last_num].y = ny;
                    last_num = temp.back().num; // 다음번호로 갱신
                }
                // i번째 좌표 업데이트
                Horses cur = temp.back();
                temp.pop_back();
                map[nx][ny].horses.push_back(cur);
                horses[i].x = nx;
                horses[i].y = ny;

                map[cx][cy].horses = temp; // 업데이트

                // 턴 종료되는지 검사
                if(map[nx][ny].horses.size() >= 4){
                    cout << turn << "\n";
                    return 0;
                } 
            }
        }


    }

    if(turn > 1000) {
        cout << "-1\n";
    }
    else cout << turn << "\n";

    return 0;
}