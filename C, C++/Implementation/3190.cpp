#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

int N, K, L, X, appleX, appleY;
char C;

// 1. char C다. C는 int가 아니라 문자이므로 char로 선언함에 주의하자
// 2. 배열 bounds 인덱스 처리할 때, 문제에서 1~N으로 주어졌다면, 배열도 1~N으로 맞추자. 

bool isMyBody(int x,  int y, vector<vector<int>> graph){
    return graph[x][y] == 1 ? true: false;
}

bool isValid(int x, int y, vector<vector<int>> graph){
    // x, y 로 이동할 수 있는지 검사
    return (x < 1 || x > N || y < 1 || y > N) ? false: true;
}

bool canMove(int x, int y, vector<vector<int>> graph){
    // 유효하지 않거나, 내 몸이라면 이동 불가
    return (!isValid(x, y, graph) || isMyBody(x, y, graph)) ? false: true;
}

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    deque<pair<int, int>> dq;
    queue<pair<int, char>> q;

    vector<vector<int>> graph(N + 1, vector<int>(N + 1, 0));

    cin >> K;

    while(K--){
        cin >> appleX >> appleY;
        graph[appleX][appleY] = 2;
    }

    cin >> L;
    while(L--){
        cin >> X >> C;
        q.push({X, C});
    }

    // 뱀 1,1 에 위치시키기
    dq.push_front({1 , 1});

    // 자기 위치 1로 표시
    graph[1][1] = 1;

    // 처음에는 오른쪽 방향
    int dir = 0;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    int time = 0;

    // 이동 시작
    while(1){
        time++;
        pair<int, int> cur = dq.front();

        int nx = cur.first + dx[dir];
        int ny = cur.second + dy[dir];

        // 움직일 수 없다면 종료
        if(!canMove(nx, ny, graph)) break;
        

        dq.push_front({nx, ny});

        // 사과 있는지 확인
        if(graph[nx][ny] == 2) graph[nx][ny] = 1;
        
        else {
            pair<int, int> tail = dq.back();
            graph[nx][ny] = 1; // 머리 1 표시
            graph[tail.first][tail.second] = 0; // 방문 해제
            dq.pop_back();
        }

        // 방향 전환
        if(time == q.front().first){
            char type = q.front().second;
            q.pop();
            switch(type){
                // dir 갱신
                case 'L':
                    if(dir == 0) dir += 4;
                    dir = (dir - 1) % 4;
                    break;
                case 'D':
                    dir = (dir + 1) % 4;
                    break;

            }
        }
    }
    cout << time << "\n";
    return 0;
}

  // <풀이과정>

    // [setup]
    // 0: 아무것도 없음, 2: 사과
    // 처음 덱에 {1,1} 넣기. 좌표, 자기 위치 1로 표시
    // 뱀이 자기 자신과 부딪히던가, 벽에 부딪히면 게임 끝
    
    // [메인로직]
        // [이동]
        // 앞에가 부딪히지 않는다면
            // 앞의 위치가 자기 자신이거나, 벽인지 확인
            // 자기자신 검사 방법
            // 1) deque에 있는지 확인 => 매번 100번씩 순회돌리면 오래걸림
            // 2) 자기 위치 1로 표시 (o)
            // 머리 push_front + 방문 표시 (1)
        // 뱀의 몸이 위치한 곳 -> deque에 담기 (앞뒤로 출입이 발생하므로)
        // 1.  머리 == 벽 || 자기자신 => 게임 끝
        // 2. 사과가 있음 => 사과 없어지고, 꼬리 이동 X
            // 그래프 1으로 바꿈 (자기 자신)
        // 3. 사과 없음 => 꼬리 하나 앞으로 (마지막 pop)
            // pop_back, 꼬리 자리 0으로 바꿈

        // [방향 갱신]
        // 현재 time이 시간 첫번째 time이라면 pop하기
        // 다음 방향 갱신
        //  - i, j라고 했을 때
        // 오른쪽, 아래, 왼쪽, 위 (고정)
        // 처음 방향 오른쪽이니까 다음은 오른쪽 가리키도록 하기
        // 다음 방향이 L이면 (dir-1)%4 인데, 음수처리
        // 다음 방향이 R이면 (dir + 1) % 4
