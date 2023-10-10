#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

#define MAX 11

int N, M, K;
int x, y, z; // (위치), 나이
struct Tree {
    int x, y, age; 
};

vector<Tree> death_trees;

struct Cell {
    int soil;
    deque<Tree> trees; // 나이가 어린 나무부터 양분을 먹어야 함 - push는 오른쪽, pop은 왼쪽
};

int soils[MAX][MAX] = {0};

Cell map[MAX][MAX];

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void input(){
    cin >> N >> M >> K;
    int soil = 0;

    for(int i = 0 ; i< N ; i++){
        for(int j = 0 ; j < N ; j++){
            cin >> soil;
            map[i][j].soil = 5; // 초기에 모든 칸은 양분이 5만큼 들어있다
            soils[i][j] = soil;
        }
    }

    // 나무들 정보 저장 - 0번부터 시작
    for(int i = 0 ; i < M ; i++){
        cin >> x >> y >> z;
        Tree temp = {x -1, y -1, z};
        map[x-1][y-1].trees.push_back(temp);
    }
}

// 봄 - 자신의 나이만큼 양분 먹고 나이 증가, 못먹는 경우 즉시 죽음 => pop하고 death_trees에 추가해주기
void getSpring(){
    for(int i = 0 ; i< N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(!map[i][j].trees.size()) continue;

            deque<Tree> temp = map[i][j].trees;
            int soil = map[i][j].soil; // 먹을 수 있는 총 양분

            int last_index = temp.size() - 1;
            int is_death = false;

            for(int t = temp.size() - 1 ; t >= 0 ; t--){                
                if(soil >= temp[t].age){
                    soil -= temp[t].age;
                    temp[t].age++; // 나이 1 증가
                } else {
                    is_death = true;
                    last_index = t;
                    break;
                }
            }
            if(is_death){
                // 마지막 인덱스 죽은 나무 처리 - 뒤에것도 양분 못 먹음
                for(int t = 0 ; t <= last_index ; t++){
                    Tree temp_tree = temp[0];
                    temp.pop_front();
                    death_trees.push_back(temp_tree);
                }
            }
            map[i][j].trees = temp; // 업데이트
            map[i][j].soil = soil;
        }
    }
}

// 여름 - death_trees에 있는 나무들 나이를 2로 나눈 값이 양분으로 추가됨
void getSummer(){
    for(int i = 0 ; i < death_trees.size() ; i++){
        Tree death_tree = death_trees[i];
        int new_soil = death_tree.age / 2;
        map[death_tree.x][death_tree.y].soil += new_soil;
    }
    death_trees.clear(); // 죽은 나무 처리 끝 - 초기화
}

// 가을 - 나무 번식, 5의 배수는 번식 가능, 인접 8칸에 나이가 1인 나무가 생김
void getAutumn(){
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(map[i][j].trees.size() == 0) continue;

            for(int t = 0 ; t < map[i][j].trees.size() ; t++){
                if(map[i][j].trees[t].age % 5 == 0){
                    for(int d = 0 ; d < 8 ; d++){
                        int nx = map[i][j].trees[t].x + dx[d]; // 제어 변수가 i가 아니라 d임
                        int ny = map[i][j].trees[t].y + dy[d];
                        if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                        map[nx][ny].trees.push_back({nx, ny, 1});
                    }
                }
            }
            
        }
    }

}

// 겨울 - 땅에 양분 추가
void getWinter(){
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            map[i][j].soil += soils[i][j];
        }
    }
}

// 1년 지나는 함수
void getYear(){

    // 봄
    getSpring();

    // 여름
    getSummer();

    // 가을
    getAutumn();

    // 겨울
    getWinter();

}


int main(void){

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // 1. 입력 - 나무 양분 및 나무들 정보 세팅
    input();

    // 2. K까지 1년 돌리기
    for(int i = 0 ; i < K ; i++){
        getYear();
    }

    // 3. 살아남은 나무 수 출력
    int alive_trees = 0;

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            alive_trees += map[i][j].trees.size();
        }
    }

    cout << alive_trees << "\n";

    return 0;
}