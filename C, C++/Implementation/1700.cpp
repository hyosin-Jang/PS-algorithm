#include <iostream>
#include <queue>
using namespace std;


int inuse[101] = {0,}; 
int n, k, product;
queue<int> order;
vector<int> v(101, 0);

int get_least_used(int cur_idx){

    // inuse에서 1인 것이 order에서 처음 등장하는 인덱스 중 가장 작은 거를 리턴하면 됨
    int pull_out_idx = 0; // point1: 헷갈리니까 이름 구별되게 + 직관적으로 짓자
    int max_num = 0;

    for(int i = 1 ; i<= k ; i++){
        if(inuse[i]){ // i가 사용중이라면, cur_idx 이후로 order에서 몇번째로 등장하는지 확인
            int flag = 0;
            for(int j = cur_idx + 1 ; j <= k ; j++){
                if(v[j] == i){
                    flag = 1;
                    // j가 큰 값의 i인덱스 가지고 있다가 리턴
                    if(max_num < j){
                        max_num = j; 
                        pull_out_idx = i;
                    }
                    break;
                }
               
            } // point2: flag == 0 인지 검사하는 위치 조심!
             if(flag ==0) return i;  
        }
    }
    return pull_out_idx;
}

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    for(int i = 0 ; i<k ; i++){
        cin >> product;
        order.push(product);
        v[i + 1] = product;
    }

    int use_cnt = 0; // 사용중인 멀티탭 개수
    int pull_out = 0;
    int cur_idx = 0;

    while(!order.empty()){
        product = order.front();
        order.pop();

        // 이미 꼽혀있다면 변동 X
        if(inuse[product] == 1){ // point3: 1~k까지로 통일, 멀티탭이 1~k니까 인덱스도 1~k로 사용하기
            cur_idx++;
            continue;
        }
        // 멀티탭 남아서 그냥 꼽을 수 있음
        if(use_cnt < n){
           inuse[product] = 1;
           use_cnt++;
        } else { 
            // 사용 안하고 있는데 못꼽는 경우 하나를 빼야 함
            int product_idx = get_least_used(cur_idx);
            inuse[product_idx] = 0;
            inuse[product] = 1;
            pull_out++; // 스위치 빼는 횟수 증가
        }
        cur_idx++;
    }
    cout << pull_out << '\n';

    return 0;
}