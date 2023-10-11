#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

pair<int, int> map[52][52]; // 물의 양, 구름 여부

// d 세팅, 1부터 시작
int dx[] = {0, 0,  -1, -1, -1, 0, 1, 1,  1};
int dy[] = {0, -1, -1, 0,  1,  1, 1, 0, -1};

struct Cloud {
    int x, y;
};

vector<Cloud> cloudes;

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    //1. 입력
    int water = 0;
    cin >> N >> M;
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= N ; j++){
            cin >> water;
            map[i][j] = {water, 0}; // 구름 없음
        }
    }

    int d, s;

    // 초기 구름
    cloudes.push_back({N, 1});
    cloudes.push_back({N, 2});
    cloudes.push_back({N-1, 1});
    cloudes.push_back({N-1, 2});

    for(int i = 0 ; i < M ; i++){
        // 처음엔 비구름 생성됨
        cin >> d >> s;

        if(d == 1 || d == 3 || d == 5 || d == 7) s %= N; // 대각선인 경우 보장 못함

        // 2-2. 모든 구름이 di방향으로 si칸 이동
        for(int i = 0 ; i < cloudes.size() ; i++){
            int nx = cloudes[i].x;
            int ny = cloudes[i].y;

            for(int ts = 0 ; ts < s ; ts++){
                nx = nx + dx[d];
                ny = ny + dy[d];

                if(nx < 1) nx = N;
                if(ny < 1) ny = N;
                if(nx > N) nx = 1;
                if(ny > N) ny = 1;
            }

            // 2-3. 각 구름에서 비가 내려, 구름이 있는칸의 물 양 1 증가
            map[nx][ny].first++;
            cloudes[i] = {nx, ny}; // 구름 위치 nx, ny로 갱신
            map[nx][ny].second = 1; // 구름 있음 (사라질 예정)
        }

        for(int i = 0 ; i < cloudes.size() ; i++){

            int add_water = 0;
            int cur_x = cloudes[i].x;
            int cur_y = cloudes[i].y;

            // 4방향 물있는 칸의 개수 세기 - 2,4,6,8
            for(int td = 2 ; td <= 8 ; td+= 2){
                int nx = cur_x + dx[td];
                int ny = cur_y + dy[td];

                if(nx < 1 || ny < 1 || nx > N || ny > N) continue;
                if(map[nx][ny].first > 0) add_water++;
            }
            map[cur_x][cur_y].first += add_water;
        }

        cloudes.clear(); // 구름 사라짐

        // 5. 바구니에 저장된 물의 양 2 이상인 모든 칸에 구름 생성, 물의 양 2 줄어듦 (3에서 구름이 사라진 칸은 안됨)
        for(int i = 1 ; i <=N ; i++){
            for(int j =1 ; j<=N ; j++){
                // 넣을 수 있는지 검사
                if(map[i][j].first >= 2 && map[i][j].second == 0){
                    cloudes.push_back({i, j});
                    map[i][j].first -= 2;
                }
                map[i][j].second = 0;
            }
        }
    }

    int answer = 0;

    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j<= N ; j++){
            answer+= map[i][j].first;
        }
    }

    cout << answer << "\n";

    return 0;
}