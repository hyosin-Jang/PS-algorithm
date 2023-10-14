#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

struct Fireball {
    int r, c, m, s, d;
};
struct Cell {
    vector<Fireball> v;
};

Cell map[52][52];

vector<Fireball> fireballs;

int dx[] = {-1, -1 ,0, 1,1,1,0 ,-1};
int dy[] = {0, 1,1,1, 0, -1, -1, -1};

int N, M, K;

// 모든 파이어볼이 자신의 방향으로 속력만큼 이동한다.
// fireballs -> temp_balls에 새로운 위치로 갱신해줌
void moveFireballs(){

    vector<Fireball> temp_balls;

    for(int i = 0 ; i< fireballs.size() ; i++){
        Fireball cur_ball = fireballs[i];
        
        int s = cur_ball.s;
        int d = cur_ball.d;
        int cx = cur_ball.r;
        int cy = cur_ball.c;
        int m = cur_ball.m;

        int optimize_s = s;
        // 이동
        if(d == 0 || d == 2 || d==4 || d==6) optimize_s %= N;
        
        // s칸 이동
        int nx = cx, ny = cy;
        for(int ts = 0 ; ts < optimize_s ; ts++){
            nx = nx + dx[d];
            ny = ny + dy[d];

            if(nx < 1) nx = N;
            if(ny < 1) ny = N;
            if(nx > N) nx = 1;
            if(ny > N) ny = 1;
        }
        map[nx][ny].v.push_back({nx, ny, m, s, d});
        temp_balls.push_back({nx, ny, m, s, d}); // 새로운 위치들로 이동 완료
    }
    fireballs = temp_balls;
}

void clearVector(){
    for(int i = 1 ; i <= N ; i++){
        for(int j =1 ; j<=N ; j++){
            map[i][j].v.clear();
        }
    }
}

void mergeAndDivideFireballs(){

    vector<Fireball> temp_fireballs;

    //  임시 vector를 하나 선언해서, 좌표의 크기가 1인 지점에 대해서는 해당 좌표에 있는 파이어볼의 정보를 삽입해 줌
    // 2이상인 지점에 대해서는 4개로 나눈 후, 이 4개의 파이어볼들을 삽입
    for(int i = 1 ; i<= N ; i++){
        for(int j = 1; j <= N ; j++){
            // 2개 이상의 파이어볼이 있다면
            if(map[i][j].v.size() == 0) continue;
            if(map[i][j].v.size() == 1){
                // 새로운 배열로 갱신
                temp_fireballs.push_back({map[i][j].v[0]});
            }
            if(map[i][j].v.size() >= 2){
                vector<Fireball> tmp_ball = map[i][j].v;

                int total_mass = 0;
                int total_speed = 0;
                int odd = 0; // 홀수
                int even = 0; // 짝수

                for(int f = 0 ; f < tmp_ball.size() ; f++){
                    total_mass += tmp_ball[f].m;
                    total_speed += tmp_ball[f].s;
                    tmp_ball[f].d % 2 == 0 ? even++ : odd++;
                }

                // 질량이 0이면 소멸
                int divide_mass = floor((double)(total_mass) / (double)5);

                if(divide_mass == 0) continue;

                int divide_speed = floor((double)(total_speed) / (double)tmp_ball.size());
                
                // 합쳐지는 파이어볼의 방향이 모두 홀수이거나 모두 짝수인 경우
                if(odd == 0 && even > 0 || even == 0 && odd > 0){
                    for(int k = 0 ; k<4 ; k++)
                        temp_fireballs.push_back({i, j, divide_mass, divide_speed, k * 2});

                } else {
                    for(int k = 0 ; k<4 ; k++)
                        temp_fireballs.push_back({i, j, divide_mass, divide_speed, k * 2 + 1});

                }
            }
        }
    }
    fireballs = temp_fireballs;
}

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;

    int r, c, m, s, d;

    for(int i = 0 ; i < M ; i++){
        cin >> r >> c >> m >> s >> d;
        fireballs.push_back({r, c, m, s, d});
    }

    while(K--){
        clearVector();

        moveFireballs();

        mergeAndDivideFireballs();
    }

    int total_mass = 0;

    for(int i = 0 ; i < fireballs.size() ; i++){
        total_mass += fireballs[i].m;
    }

    cout << total_mass << "\n";

    return 0;
}