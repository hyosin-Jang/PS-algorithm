#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};


bool isValid(int r, int c, int N, int M){
    return (r >= 0 && r < N && c >=0 && c < M) ? true: false;
}

vector<vector<int>> rotateBoard(vector<vector<int>> board){
    int N = board.size();
    int M = board[0].size();    

    vector<vector<int>> new_board(M, vector<int>(N, 0)); // M x N

    for(int i = 0 ; i< N ; i++){
        for(int j = 0 ; j < M ; j++){
            new_board[j][N - 1 - i] = board[i][j];
        }
    }
    return new_board;
}

void printBoard(vector<vector<int>> board){
    cout << "\n-------board start-------\n";
    for(int i = 0 ; i< board.size() ; i++){
        for(int j = 0 ; j <board[0].size() ; j++){
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n-------board end-------\n";
}

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    vector<vector<int>> board(N, vector<int>(M, 0));

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            cin >> board[i][j];
        }
    }
    // 위: 0, 오른쪽: 1, 아래: 2, 왼쪽: 3
    // 좌우 반전을 고려해, 3번 4번 도형은 좌우 반전한 모양도 추가
    vector<vector<int>> puzzles = {{ 1, 1, 1 }, {1, 2, 3}, {2, 2, 1}, {2, 1, 2}, {1, 2, 0, 1}, {2, 2, 3}, {2, 3, 2}};

    int max_cnt = 0;
    for(int dir = 0 ; dir < 4 ; dir++){
        for(int i = 0 ; i < board.size() ; i++){
            for(int j = 0 ; j < board[0].size() ; j++){
                for(int p = 0 ; p < puzzles.size() ; p++){
                    int cnt = board[i][j];
                    vector<int> puzzle = puzzles[p];
                    int cx = i, cy = j;
                    bool valid_flag = 1;

                    for(int c = 0 ; c < puzzle.size() ; c++){
                        cx += dx[puzzle[c]];
                        cy += dy[puzzle[c]];
                        
                        if(isValid(cx, cy, board.size(), board[0].size())) cnt += board[cx][cy];   
                        else {
                            valid_flag = 0;
                            break;
                        };
                     }
                     // 퍼즐이 들어갈 수 있는 경우임 cnt max로 갱신
                     if(valid_flag == 1){
                        if(p == 4) cnt -= board[i][j+1]; // 5번 도형은 가운데 칸이 두 번 더해졌으므로 한번 빼기 
                        max_cnt = max(max_cnt, cnt);
                     }
                }
            }
        }
        board = rotateBoard(board); 
    }
    cout << max_cnt << "\n";
    return 0;
}