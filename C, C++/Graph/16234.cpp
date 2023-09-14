#include <iostream>
#include <vector>
#include <queue>
#include <cmath> // floor, ceil, round
#include <string.h> // memset
using namespace std;

#define MAX 51
int N, L, R;
int cnt = 1;
int day = 0;

// 1. 초기화할 때 웬만하면 크기를 N으로 하지말고, MAX로 해버리자! - segfault주의
// 2. r, c가 다른 변수랑 헷갈릴 수 있기 때문에 (row, col)
//    처음에 입력받는 변수는 대문자로 지정하자
vector<vector<int>> country(MAX, vector<int>(MAX, 0));
int visited[MAX][MAX] = {0};

int dx[4] = {0 ,0, -1, 1};
int dy[4] = {1, -1, 0, 0};

bool canMove(int r, int c, int nx, int ny){
    int diff = abs(country[r][c] - country[nx][ny]);    
    if(diff >= L && diff <= R) return true;
    return false;
}

void dfs(int r, int c, vector<pair<int, int>> &result){
    for(int i = 0 ; i< 4 ; i++){
        int nx = r + dx[i];
        int ny = c + dy[i];

        if(visited[nx][ny] == 0 && nx >=0 && nx < N && ny >= 0 && ny< N){
            if(canMove(r, c, nx, ny)){
                visited[nx][ny] = 1;
                result.push_back({nx, ny});
                cnt++; // 연합 국가 개수
                dfs(nx, ny, result);
            }
        }
    }  
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> L >> R;

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j< N ;j++){
            cin >> country[i][j];
        }
    }

    // cnt: 1, vector: {i, j}
    queue<pair<int, vector<pair<int, int>>>> q;

    int flag = 0;
    while(1){
        memset(visited, 0, sizeof(visited[0][0]) * MAX * MAX);
        
        flag = 0;
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j< N ;j++){
                cnt = 1;
                vector<pair<int, int>> result;
                visited[i][j] = 1;
                dfs(i, j, result);
                if(cnt > 1){ // 인구이동 일어남!
                    flag = 1;
                    result.push_back({i, j});
                    q.push({cnt, result});
                }
            }
        }
        if(flag == 0) break;
    
        while(!q.empty()){
            int cnt = q.front().first; // 국가 수
            vector<pair<int, int>> coord = q.front().second; // 좌표
            q.pop();

            int sum = 0;
            for(int i = 0 ; i< coord.size() ; i++){
                sum += country[coord[i].first][coord[i].second];
            }  
            int new_people = floor(sum / cnt);

            for(int i = 0 ; i<coord.size() ; i++){
                country[coord[i].first][coord[i].second] = new_people;
            }
        }
        day++;
    }
    cout << day << "\n";
    return 0;
}


// memset
// 시작주소, 초기화값, 배열크기
// 동일 scope에 대해서는 memset(arr, 0 , sizeof(arr))
// 함수 내에서 선언되지 않은 배열이라면 배열명이 배열을 가리키는 포인터가 됨
// 따라서 sizeof(arr)이 arr의 size를 정상적으로 반환하지 않음
// memset(array, 0, sizeof(array[0][0]) * m * n);


// 풀이과정
// while(1)
// 2중 for문
// memset 초기화
    //  cnt = 1
    //  dfs => 인접한 애들 방문표시 후 다 큐에 넣기
    // 큐에 좌표를 넣으면, cnt는 어떻게 표시하지?
    //  cnt는 임의로
    //  cnt = {i, j} => 1
    //  cnt > 1 이면 인구 이동 있다는 뜻
    // cnt: [{i,j}] 이렇게 큐에 넣어야겠다!!
// 나라들 인구 수 갱신 (한번에 하도록 !! 주의)
// 없으면 종료 => 날짜 수 리턴
