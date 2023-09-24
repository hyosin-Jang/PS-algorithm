#include <iostream>
#include <vector>
#include <deque>
#include <cmath>
using namespace std;

// 덱 쓰기 위해 인데스를 0~3, 0~7로 설정
vector<deque<int>> wheel(4, deque<int>(8, 0));
int K;
int num, dir;

vector<pair<int, int>> rotate_list; // 돌릴 수레바퀴 번호, 방향

// 1. C++ 거듭제곱 계산법
//  - c++에서는 거듭제곱근 계산할 때, ** (이중별표 연산자 작동 안함)
//  - 1) <cmath>의 pow 사용
//  - 2) 루프를 이용하여 직접 계산

// 2. rotate_list.claer()
//  - 톱니바퀴 회전 후, 다음 명령을 위해 초기화하기

// 3. 입력이 공백 없는 string 형태로 주어짐에 유의하기
//  - 100011 => string으로 입력받은 후 각 문자에서 '0'을 빼서 숫자로 치환하자!

void checkLeft(int num, int dir){
    if(num == 0) return; 
    if(wheel[num][6] == wheel[num-1][2]) return;
    rotate_list.push_back({num-1, dir * -1});

    return checkLeft(num -1, dir * -1);
}


void checkRight(int num, int dir){
    if(num == 3) return; 
    if(wheel[num][2] == wheel[num + 1][6]) return;
    rotate_list.push_back({num + 1, dir * -1});
    return checkRight(num + 1, dir * -1);
}

void rotate(){
    for(int i = 0 ; i< rotate_list.size() ; i++){
        pair<int, int> cur = rotate_list[i]; // 번호, 방향

        // 새로운 deque으로 선언해줬기 때문에 다시 해당 위치에 넣어줘야 변경 사항이 반영됨
        deque<int> cur_wheel = wheel[cur.first];
        // 시계방향 => 한칸씩 오른족으로 이동
        if(cur.second == 1){
            int last = cur_wheel.back();
            cur_wheel.pop_back();
            cur_wheel.push_front(last);
        } else {
        // 반시계 방향 => 한칸씩 왼쪽으로 이동, 앞에서 빼고 뒤에 넣기
            int first = cur_wheel.front();
            cur_wheel.pop_front();
            cur_wheel.push_back(first); 
        }

        wheel[cur.first] = cur_wheel; 
    }
}

void print_rotate_list(){
    for(int i = 0 ; i< rotate_list.size() ; i++){
        cout << rotate_list[i].first << " " << rotate_list[i].second << "\n";
    }
    cout << "\n";
}

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    string temp;
    for(int i = 0 ; i < 4 ; i++){
        cin >> temp;
        for(int j = 0 ; j < 8 ; j++){
            wheel[i][j] = (temp[j] - '0');
        }
    }
    cin >> K;

    while(K--){
        cin >> num >> dir;
        num -= 1;
        // 자기 자신 넣기
        rotate_list.push_back({num, dir});
        checkLeft(num, dir);
        checkRight(num, dir);
        rotate();

        rotate_list.clear();
    }

    int count = 0;
    for(int i = 0 ; i< 4 ; i++){
        count += (wheel[i].front() == 1 ? pow(2, i) : 0);
    }
    cout << count << "\n";

    return 0;
}