#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define REMOVED -100
int N, M;

struct BlockGroup{
    int normal_num = 0;
    int rainbow_num = 0;
    vector<pair<int, int>> blocks;
    int color = -1; // 블록 그룹 대표 색상
};

BlockGroup cur_group; // 현재 dfs 수행하는 그룹
BlockGroup largest_group = {0, 0, {}}; // 가장 큰 그룹


int board[21][21] = {0};
int visited[21][21] = {0};
int score = 0;
int rainbow_visited[21][21] = {0};


// bg block에 속한 그룹들의 기준 블록 구하는 함수
pair<int, int> getStandardBlock(BlockGroup& bg){
    pair<int, int> standard = {21, 21};
    for(int i = 0 ; i < bg.blocks.size() ; i++){
        int cur_x = bg.blocks[i].first;
        int cur_y = bg.blocks[i].second;

        // 행과 열이 가장 작은 일반 블록을 기준으로 함
        // 여기에 일반 블록이 없는 경우 없음 - 최소 하나는 일반 블록 들어있음
        if(board[cur_x][cur_y] != 0){ // 
            if(cur_x < standard.first){
                standard.first = cur_x;
                standard.second = cur_y;
            } else if(cur_x == standard.first && cur_y < standard.second){
                standard.first = cur_x;
                standard.second = cur_y;
            }
        }
    }
    return standard;
}

struct compare{
    bool operator()(BlockGroup &b1, BlockGroup &b2){
        if(b1.blocks.size() == b2.blocks.size()){
            if(b1.rainbow_num == b2.rainbow_num){
                pair<int, int> standard_b1 = getStandardBlock(b1);
                pair<int, int> standard_b2 = getStandardBlock(b2);
                // 행이 가장 큰 것
                if(standard_b1.first == standard_b2.first){
                    return standard_b1.second < standard_b2.second;
                }
                return standard_b1.first < standard_b2.first;
            }
            return b1.rainbow_num < b2.rainbow_num;
        }
        return b1.blocks.size() < b2.blocks.size();
    }
};

priority_queue<BlockGroup, vector<BlockGroup>, compare> pq;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0 ,0};

void dfs(int r, int c){
    if(cur_group.blocks.size() >= 2 && cur_group.normal_num >= 1){
        if(pq.empty()){
            pq.push(cur_group);
        } else{
            BlockGroup largest = pq.top();
            if(largest.blocks.size() <= cur_group.blocks.size()) pq.push(cur_group);
        }
    }
    
    for(int i = 0 ; i < 4 ; i++){
        int nx = r + dx[i];
        int ny = c + dy[i];

        // 검은 블록, 제거된 블록, 경계 넘는 블록인 경우 패스
        if(nx < 0 || ny < 0 || nx >= N || ny >= N || board[nx][ny] == -1 || board[nx][ny] == REMOVED) continue;

        // 무지개인 경우, 이번 map에서 방문하지 않은 곳 방문 가능
        if(board[nx][ny] == 0 && rainbow_visited[nx][ny] == 0){
            rainbow_visited[nx][ny] = 1;
            cur_group.blocks.push_back({nx, ny});
            cur_group.rainbow_num++;
            dfs(nx, ny); // 0이거나 색상 있음
        }

        // 일반 블록은 색깔이 같고 방문하지 않은 곳만 방문 가능
        else if(board[nx][ny] >= 1 && board[nx][ny] <= M && visited[nx][ny] == 0){
            if(cur_group.color != -1 && board[nx][ny] != cur_group.color) continue; // 현재 그룹색이 지정되어 있는데 일반 블록이 색상이 다르다면
            
            // 무지개 블록에서 시작한 경우 대표 색상 지정
            if(cur_group.color == -1){
                cur_group.color = board[nx][ny];
            }
            visited[nx][ny] = 1;
            cur_group.blocks.push_back({nx, ny});
            cur_group.normal_num++;
            cur_group.color = board[nx][ny];
            dfs(nx, ny);
        }

    }
}

void reset_rainbow(){
    for(int i = 0 ; i < 21 ; i++){
        for(int j = 0 ; j < 21 ; j++){
            rainbow_visited[i][j] = 0;
        }
    }
}
void reset_visited(){
    for(int i = 0 ; i < 21 ; i++){
        for(int j = 0 ; j < 21 ; j++){
            visited[i][j] = 0;
        }
    }
}

void getLargestBlockGroup(){

    reset_visited();

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(board[i][j] == REMOVED) continue;

            // 검은 블록이 아니라면
            if(board[i][j] != -1){
                cur_group = {0, 0, {}}; // 초기화
                
                // 일반 블록인 경우 방문하지 않아야 방문할 수 있음
                if(board[i][j] >= 1 && board[i][j] <= M && visited[i][j] == 0){
                    reset_rainbow(); // 일반 블록 찾을 때도 rainbow reset 해야 함
                    visited[i][j] = 1;
                    cur_group.blocks.push_back({i, j});
                    cur_group.normal_num++; // 일반 블록 개수 증가
                    cur_group.color = board[i][j];
                    dfs(i, j);
                }
                else if (board[i][j]== 0){ // 무지개인 경우
                    // rainbow 초기화
                    reset_rainbow();
                    rainbow_visited[i][j] = 1; 
                    cur_group.blocks.push_back({i, j});
                    cur_group.rainbow_num++;
                    dfs(i, j);
                }
            }
        }
    }
}

// 블록들 제거
void removeLargestBlockGroup(){
    for(int i = 0 ; i < largest_group.blocks.size() ; i++){
        int cur_x = largest_group.blocks[i].first;
        int cur_y = largest_group.blocks[i].second;
        board[cur_x][cur_y] = REMOVED;
    }
    largest_group = {0, 0, {}}; // 초기화
}

void applyGravity(){

    int temp_board[21][21] = {0};

    for(int i = 0 ; i < N ; i++){
        vector<pair<pair<int, int>, int>> temp_row; // {숫자, 기준점}, 몇번째 등장했는지
        int cur_standard = N;
        int cnt = 0;

        // 아래로 내리기
        for(int j = N-1 ; j>=0 ; j--){
            temp_board[j][i] = REMOVED;
            if(board[j][i] == -1) {
                temp_board[j][i] = -1;
                cur_standard = j;
                cnt = 0;
            }
            if(board[j][i] != REMOVED && board[j][i] != -1){
                cnt++;
                temp_row.push_back({{board[j][i], cur_standard}, cnt});
            }
        }

        // 남은 것들 옮겨주기
        for(int tc = 0 ; tc < temp_row.size() ; tc++){
            int cur_standard_idx = temp_row[tc].first.second;
            int num = temp_row[tc].first.first;
            int diff = temp_row[tc].second;
            temp_board[cur_standard_idx - diff][i] = num;
            
        }   
    }

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            board[i][j] = temp_board[i][j];
        }
    } 
}

//  반시계 90도 회전
void rotateBoard(){

    int temp_board[21][21] = {0};

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            temp_board[N-1-j][i] = board[i][j];
        }
    }

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            board[i][j] = temp_board[i][j];
        }
    }

}




int main(void){

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j<N ; j++){
            cin >> board[i][j];
        }
    }


    while(1){
        // 크기가 가장 큰 블록 그룹 찾기 - largest block에 저장
        getLargestBlockGroup();

        // 1에서 찾은 블록 그룹의 모든 블록 제거 - 블록그룹이 없다면 종료
        if(pq.empty()){
            cout << score << "\n";
            return 0;
        }

        largest_group = pq.top();

        // 점수 획득
        score += largest_group.blocks.size() * largest_group.blocks.size();
        removeLargestBlockGroup();

        applyGravity(); // 중력 적용

        rotateBoard(); // 반시계 90도 회전 - 새로운 board로 갱신

        applyGravity();

        while(!pq.empty()) pq.pop(); 

    }

    return 0;
}