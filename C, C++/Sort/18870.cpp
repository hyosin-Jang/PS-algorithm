#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector <int> v(n); // 원본 벡터

    // 입력
    for(int i = 0 ; i<n ; i++){
        cin >> v[i];
    }

    // 벡터를 복사할 때, 초기값으로 다른 벡터를 넣어줄 수 있음
    vector<int> cv(v); // 원본 벡터를 복사해서 중복 된 값을 제거하고 정렬을 시행할 벡터
    sort(cv.begin(), cv.end());

    // 중복 제거
    cv.erase(unique(cv.begin(), cv.end()), cv.end());
    
    for(int i = 0 ; i< n ; i++){
        // i번째 요소값의 위치 it
        // lower_bound는 찾으려는 key값보다 크거나 같은 숫자가 배열에서 처음 등장하는 위치를 찾아줌
        // 전제는 탐색을 진행할 배열 혹은 벡터가 오름차순 정렬되어 있어야 함
        auto it  = lower_bound(cv.begin(), cv.end(), v[i]);

        // lower_bound의 반환형은 Iterator이므로 실제로 몇 번째 인덱스인지 알고 싶으면
        // 배열의 첫 주소를 가리키는 배열의 이름을 빼주면 됨
        // 배열의 경우 (it - arr)

        // it에서 cv벡터의 시작 주소값을 빼준 값이 답
        // 반대의 경우로, upper_bound가 있음
        // O(logN)으로 탐색 가능
        cout << it - cv.begin() << ' ';
    }

    return 0;
}