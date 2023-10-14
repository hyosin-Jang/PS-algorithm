#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 1시간 31분
// 모노미노도미노 2 - 1트 solve

// 입력
int N;
int green_board[10][5]; // 위에는 red, 연한색 있음
int blue_board[5][10]; // 왼쪽에 red, 연한색 있음

// 출력
int score = 0;

// 블록의 이동은 다른 블록을 만나거나 보드의 경계를 만나기 전까지 계속해서 이동한다.
void move_green(int t, int x, int y){
    if(t==1){
        for(int r = 4 ; r <= 9 ; r++){
            if(green_board[r][y] == 1){ // 다른 블록을 만나거나 경계일 때까지 이동
                green_board[r-1][y] = 1;
                return; 
            }
        }
        green_board[9][y] = 1;
        return;
    }

    else if (t==2){
        for(int r = 4 ; r <= 9 ; r++){
            if(green_board[r][y] == 1 || green_board[r][y+1] == 1){
                green_board[r - 1][y] = 1;
                green_board[r - 1][y+1] = 1;
                return; 
            }
        }
        green_board[9][y] = 1; 
        green_board[9][y+1] = 1; 
        return; 
    }
    else if (t==3){
        for(int r = 4 ; r <= 9 ; r++){
            if(green_board[r][y] == 1){
                green_board[r-1][y] = 1;
                green_board[r-2][y] = 1;
                return; 
            }
        }
        green_board[9][y] = 1;
        green_board[8][y] = 1; 
    }
}

void move_blue(int t, int x, int y){
    if(t==1){
        for(int c = 4 ; c <= 9 ; c++){
            // 블록인 곳을 만나면 거기에 위치
            if(blue_board[x][c] == 1){
                blue_board[x][c-1] = 1;
                return; 
            }
        }
        blue_board[x][9] = 1; // 제일 아래
        return;
    }

    else if (t==2){
        for(int c = 4 ; c <= 9 ; c++){
            if(blue_board[x][c] == 1){
                blue_board[x][c-1] = 1;
                blue_board[x][c-2] = 1;
                return; 
            }
        }
        blue_board[x][9] = 1;
        blue_board[x][8] = 1;
        return;
    }
    else if (t==3){
        for(int c = 4 ; c <= 9 ; c++){
            if(blue_board[x][c] == 1 || blue_board[x+1][c] == 1 ){
                blue_board[x][c-1] = 1;
                blue_board[x+1][c-1] = 1;
                return; 
            }
        }
        blue_board[x][9] = 1;
        blue_board[x+1][9] = 1;
    }

}

void setBlock(int t, int x, int y){
    // t = 1: 크기가 1×1인 블록을 (x, y)에 놓은 경우
    if(t==1){
        move_green(t, x, y);
        move_blue(t, x, y);
    }
    // t = 2: 크기가 1×2인 블록을 (x, y), (x, y+1)에 놓은 경우
    else if (t == 2){
        move_green(t, x, y);
        move_blue(t, x, y);

    }
    // t = 3: 크기가 2×1인 블록을 (x, y), (x+1, y)에 놓은 경우
    else if (t==3){
        move_green(t, x, y);
        move_blue(t, x, y);
    }
}

vector<int> removeGreen(){
    vector<int> idx; // 제거되어야 할 인덱스, 최대 2개

    for(int r = 9 ; r >= 4 ; r--){ 
        if(idx.size() == 2) return idx;
        
        bool remove = true;
        for(int c = 0 ; c < 4 ; c++){
            // 다 1이여야 함
            if(green_board[r][c] == 0){
                remove = false;
                break;
            }
        }
        if(remove) idx.push_back(r);
        
    }
    return idx;
}

vector<int> removeBlue(){
    vector<int> idx; 
    for(int c = 9 ; c >= 4 ; c--){
        if(idx.size() == 2) return idx;
        
        bool remove = true;
        for(int r = 0 ; r < 4 ; r++){
            // 다 1이여야 함
            if(blue_board[r][c] == 0){
                remove = false;
                break;
            }
        }
        if(remove) idx.push_back(c);
    }
    return idx;
}

void downBlue(vector<int> idx){
    int offset = idx.size();

    for(int c = idx[0] ; c >= 4 ; c--){
        for(int r = 0 ; r < 4 ; r++){
            blue_board[r][c] = blue_board[r][c-offset];
        }
    }
}


void downGreen(vector<int> idx){
    int offset = idx.size();

    for(int r = idx[0] ; r >= 4 ; r--){
        for(int c = 0 ; c < 4 ; c++){
            green_board[r][c] = green_board[r - offset][c];
        }
    }
}
void removeAndDownGreen(){
    vector<int> idx = removeGreen();
    if(idx.size() == 0) return;
    score += idx.size();
    downGreen(idx);
}

void removeAndRightBlue(){
    vector<int> idx = removeBlue();
    if(idx.size() == 0) return;
    score += idx.size();
    downBlue(idx);
}

void moveLightGreen(){
    int row = 0;

    for(int r = 5 ; r >= 4 ; r--){
        for(int c = 0 ; c < 4 ; c++){
            if(green_board[r][c] == 1){ // 하나라도 연한 블록에 있는 경우
                row++;
                break;
            }
        }
    }
    if(row == 0) return;
    if(row == 1){
        vector<int> temp = {9};
        downGreen(temp);
    }
    else if (row == 2){
        vector<int> temp = {9, 8};
        downGreen(temp);
    }
}

void moveLightBlue(){
    int col = 0;
    for(int c = 5 ; c >= 4 ; c--){
        for(int r = 0 ; r < 4 ; r++){
            if(blue_board[r][c] == 1){
                col++;
                break;
            }
        }
    }
    if(col == 0) return;
    if(col == 1){
        vector<int> temp = {9};
        downBlue(temp);
    }
    else if (col == 2){
        vector<int> temp = {9, 8};
        downBlue(temp);
    }
}

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    int t, x, y;

    for(int i = 0 ; i <  N; i++){
        cin >> t >> x >> y;

        // 1. 블록 놓고, 아래, 오른쪽으로 이동
        setBlock(t, x, y);

        // 2. 행이 타일로 가득 차있으면 사라짐
        // - 초록색 보드는 행 체크
        removeAndDownGreen();

        // - 파란색 보드는 열 체크
        removeAndRightBlue();

        // 3. 연한색에 칸이 있는 만큼 오른쪽으로 이동
        // - 초록색 이동
        moveLightGreen();

        // - 파란색 이동
        moveLightBlue();

        
    }

    cout << score << "\n";

    int left_num = 0;

    for(int r = 9 ; r >= 4 ; r--){
        for(int c= 0 ; c<4 ;c++){
            if(green_board[r][c] == 1) left_num++;
        }
    }

    for(int c = 9 ; c >= 4 ; c--){
        for(int r = 0 ; r < 4 ; r++){
            if(blue_board[r][c] == 1) left_num++;
        }
    }
    // 얻은 점수와 보드에 칸이 있는 개수 출력
    cout << left_num << "\n";

    return 0;
}