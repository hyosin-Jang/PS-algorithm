#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 20

int N;
int board[MAX + 1][MAX + 1];
int visited[MAX + 1][MAX + 1];
vector<vector<int>> v(MAX * MAX + 1);
// N*N 명이 있을 수 있으므로 v(20 * 20 + 1)로 선언

struct Seat{
    int x;
    int y;
    int near_like;
    int near_empty;
};

struct cmp{
    bool operator()(Seat &seat1, Seat &seat2){
        if(seat1.near_like == seat2.near_like){
            if(seat1.near_empty == seat2.near_empty){
                if(seat1.x == seat2.x){
                    return seat1.y > seat2.y;
                }
                return seat1.x > seat2.x;
            }
            return seat1.near_empty < seat2.near_empty;
        }
        return seat1.near_like < seat2.near_like;
    }
};

// i, j에서 네 방향 탐색하면서 좋아하는 학생 수, 비어있는 칸 개수 리턴
pair<int, int> getLikeEmpty (int r, int c, int num){
    int like = 0;
    int empty = 0;

    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};

    for(int i = 0 ; i < 4 ; i++){
        int nx = r + dx[i];
        int ny = c + dy[i];
        if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

        // 좋아하는 학생인지 검사
        for(int j = 0 ; j < v[num].size() ; j++){
            if(v[num][j] == board[nx][ny]){
                like++;
                break;
            }
        }
        // 빈칸인지 검사
        if(board[nx][ny] == 0) empty++;
    }
    return {like, empty};
}
void getSeat(int num){
    // 비어있는 칸 중에서 좋아하는 학생이 인접한 칸에 가장 많은 칸으로 자리를 정한다.
    // - 각 좌표마다 인접한 칸에 (좋아하는 학생 수, 비어있는 칸) 몇명, 몇칸인지 계산
    priority_queue<Seat, vector<Seat>, cmp> pq;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(board[i][j] != 0) continue;
            pair<int, int> result = getLikeEmpty(i, j, num);  // 좋아하는 학생수, 비어있는 칸
            pq.push({i, j, result.first, result.second});
        }
    }
    Seat cur = pq.top();
    board[cur.x][cur.y] = num; // num번 학생 착석
}

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    int num, like1, like2, like3, like4;

    for(int i = 0 ; i < N * N ; i++){
        cin >> num >> like1 >> like2 >> like3 >> like4;
        v[num].push_back(like1);
        v[num].push_back(like2);
        v[num].push_back(like3);
        v[num].push_back(like4);
        getSeat(num);
    }

    int total = 0; // 총 만족도

    for(int i = 0; i <N ; i++){
        for(int j = 0 ; j<N ; j++){
            int result = getLikeEmpty(i, j, board[i][j]).first;
            switch(result){
                case 1:
                    total += 1;
                    break;
                case 2:
                    total += 10;
                    break;
                case 3:
                    total += 100;
                    break;
                case 4:
                    total += 1000;
                    break;
            }
        }
    }

    cout << total << "\n";

    return 0;
}