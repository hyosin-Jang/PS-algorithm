#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;


int N, M, T;
#define REMOVED -100 // T가 최대 50이고, 원판에 적힌 수의 최솟값이 1이므로 -100까지는 도달 불가

// 1시간 32분, 1트 solve
// deque.push_back이 아니라 push_front라고 써서 찾느라 디버깅했음
// 처음 코드짤 때 주의 기울여서 꼼꼼하게 보자!!

// 각 원판은 num, deque
struct CircleBoard {
    int idx; // 원판 고유 번호 (= 반지름) 1 ~ N
    deque<pair<int, int>> num; // {원판에 적힌 번호들, 지웠는지 여부} (12시부터 시계방향) (1이면 지웠다는 뜻) 인덱스 0부터 시작
};

// 원판 번호에 맞추어 1부터 시작
CircleBoard board[51];


void printBoard(){
    for(int i = 1;  i <= N ; i++){
        for(int j = 0 ; j < M ; j++){
            if(board[i].num[j].second == 0){
                cout << board[i].num[j].first << " ";
            }
            else cout << "x ";
        }
        cout << "\n";
    }   
    cout << "\n";
}


void updateNumber(int x, int d, int k){
    // i번 원판에 대해서 인접하면서 수가 같은 것 모두 찾기 - 지운 수는 0으로 표시
    bool isRemove = false;
    int cnt = 0, total = 0;

    for(int i = 1 ; i <= N ; i++){
        // 1. 같은 원판 내에서 검사 - 덱 앞 뒤, 중간 검사
        //지울 때, 바로 지워버리면 안됨. 끝나고 한번에 지워야 함

        deque<pair<int, int>> curCircle = board[i].num;
        // 1. 0~1, 1~2, ..., M-2, M-1 검사
        for(int tn = 0 ; tn < M -1 ; tn++){
            int cur_num = curCircle[tn].first;
            if(cur_num == REMOVED) continue;

            // 안지워졌다는 뜻이니까 남아있는 수 누적 + 개수 같이 세줌 (아래서 평균 구할 때 사용)
            // 이번에 지워진다면 어차피 써먹지 못할 값이니까 상관 없음
            cnt++;
            total += cur_num;
    
            if(cur_num == curCircle[tn + 1].first){
                curCircle[tn].second = 1; // 지워주려고 1 표시
                curCircle[tn + 1].second = 1;
                isRemove = true; // 하나라도 지운 것이 있다면 플래그 변경
            }
        }

        // 2. M-1 ~ 0 같은지 검사
        if((curCircle[M-1].first != REMOVED) && (curCircle[M-1].first == curCircle[0].first)){
            curCircle[M-1].second = 1;
            curCircle[0].second = 1;
            isRemove = true;
        }

        // 마지막은 따로 추가
        if(curCircle[M-1].first != REMOVED){
            cnt++;
            total += curCircle[M-1].first;
        }

        board[i].num = curCircle; // 업데이트

        // 2. 다른 원판 양옆 인접 - 양쪽 검사 
        if(i == N) continue; // 이미 N-1번째에서 검사했기 때문에 패스

        for(int tm = 0 ; tm < M ; tm++){
            if(board[i].num[tm].first != REMOVED && board[i].num[tm].first == board[i+1].num[tm].first){
                board[i].num[tm].second = 1;
                board[i+1].num[tm].second = 1;
                isRemove = true;
            }
        } 
    }

    // 지워줄 숫자를 REMOVED로 바꿔주기
    if(isRemove){
        for(int i = 1;  i <= N ; i++){
            for(int j = 0 ; j < M ; j++){
                if(board[i].num[j].second == 1){
                    board[i].num[j].first = REMOVED;
                }
            }
        }   
    }

    // 지운 숫자가 없다면 평균 이랑 값 비교해서 +1/-1 연산 수행
    else{
        double average = (double)(total) / (double)(cnt);

        for(int i = 1;  i <= N ; i++){
            for(int j = 0 ; j < M ; j++){
                int cur_num = board[i].num[j].first;
                if(board[i].num[j].second == 0){
                    if(cur_num > average) board[i].num[j].first--;
                     else if(cur_num < average) board[i].num[j].first++;
                    
                }
            }
        }   
    }
}

// x의 배수인 원판을 d 방향으로 k번 회전
void rotate(int x, int d, int k){
    for(int i = x ; i <= N ; i+= x){
        // 시계방향 회전 - 뒤에서 뽑아서 앞에 추가
        k %= M; // 원판은 같은 결과가 나오는 주기가 M이므로 M으로 나눈 나머지 사용
        if(d == 0){
            for(int tk = 0 ; tk < k ; tk++){
                pair<int, int> last = board[i].num.back();
                board[i].num.pop_back();
                board[i].num.push_front(last);
            }
        } else {
            // 반시계 방향 회전 - 앞에서 뽑아서 뒤에 추가
            for(int tk = 0 ; tk < k ; tk++){
                pair<int, int> first = board[i].num.front();
                board[i].num.pop_front();
                board[i].num.push_back(first);
            }
        }
    }
}

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int x, d, k, tmp;
    cin >> N >> M >> T;


    for(int i = 1 ; i <= N ; i++){ // i: 원판 번호
        board[i].idx = i; // 인덱스로 접근해도 똑같지만 그냥 넣어주기
        for(int j = 0 ; j < M ; j++){
            cin >> tmp;
            board[i].num.push_back({tmp, 0});
        }
    }

    while(T--){
        cin >> x >> d >> k;
        rotate(x, d, k);
        updateNumber(x, d, k);
        //printBoard();
    }

    int answer = 0;
    for(int i = 1;  i <= N ; i++){
        for(int j = 0 ; j < M ; j++){
            if(board[i].num[j].second == 0){
                answer += board[i].num[j].first;
            }
        }
    }   

    cout << answer << "\n";
    return 0;
}