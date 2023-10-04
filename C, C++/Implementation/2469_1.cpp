#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

// cmath: Std 네임 스페이스 st::sqrt, std::sin, std::cos으로 사용
// math.h: 전역 네임스페이스 sqrt, sin, cos으로 사용

// 일반적으로 c++에서는 cmaht헤더를 사용하는 것을 권장
// C++ 특화된 기능을 사용할 수 있고, std 네임스페이스를 사용하므로 코드 가독성 높일 수 있음

// ???...를 제외한 바로 위칸 과 아래 칸의 결과는 알고 있기 때문에 swap을 좌우로 한번만 할 수 있음
// 모든 알파벳 배열들이 1칸 이상 차이가 나면 안되고 두 알파벳이 교환했을 때 서로 같아져야 함

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int K, N, stop; // 사람 수, 사다리 행 길이, ?가 나오는 행 인덱스
    cin >> K >> N;
    string start, end, answer; // 시작 알파벳, 결과 알파벳, 출력할 정답
    vector<string> v; // 사다리 정보 저장
    
    // 시작은 A~Z
    for(int i = 0 ;i < K ; i++){
        start.push_back('A' + i);
    }
    cin >> end;

    // 사다리 정보 입력받고 ? 나오는 행 인덱스 찾기
    for(int i = 0 ; i < N ; i++){
        string str;
        cin >> str;
        v.push_back(str);
        if(str[0] == '?') stop = i;
    }

    // 시작 알파벳에서 ?행 전까지 알파벳 순서 수정
    for(int i = 0 ; i<stop ; i++){
        for(int j = 0 ; j < v[i].size() ; j++){ // K
            if(v[i][j] == '-'){
                swap(start[j], start[j+1]); // j랑 j+1번째 교환
            }
        }
    }

    // 결과 알파벳에서 ?행 전까지 알파벳 순서 수정
    for(int i = N-1 ; i > stop ; i--){
        for(int j = 0 ; j < v[i].size() ; j++){
            if(v[i][j] == '-'){
                // c++에서 문자열은 동적할당, 원본이 변경됨
                swap(end[j], end[j+1]);
            }
        }
    }

    // 알파벳 비교
    bool flag = true;
    for(int i = 0 ; i <K-1 ; i++){
        if(start[i] == end[i]) answer.push_back('*');
        // depth가 1이므로 무조건 1칸 차이나야 함
         else if((start[i] == end[i+1]) && (end[i] == start[i+1])){
            answer.push_back('-');
            swap(start[i], start[i+1]);
        } else{
            flag =false;
            break;
        }
    }
    if(!flag){
        for(int i = 0 ; i <K-1 ; i++){
            cout << 'x';
        }
        cout << "\n";
    } else cout << answer;
    
    return 0;
}