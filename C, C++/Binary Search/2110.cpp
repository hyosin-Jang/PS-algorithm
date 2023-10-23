#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 가장 인접한 두 공유기 사이의 거리가 최대인 것
// = 모든 공유기들의 간격이 공평하게 설치되기를 원함
// 따라서 모든 공유기들을 공평하게 설치할 수 있는 간격을 이분 탐색을 통해서 찾아야 함

vector<int> router;

// 최대 간격을 가지는 공유기 위치 찾기
int find_max_dist(int n, int c){

    // 기준 간격 이분 탐색을 위한 변수
    int l_dist = 1; // 첫 번째 공유기에서 첫번째 공유기까지의 간격
    int r_dist = router[n-1] - router[0]; // 첫번째 공유기에서 마지막 공유기까지의 간격

    // 원래 간격
    int result_dist = 0;

    // 이분법을 사용해, 모든 간격 탐색이 끝날때까지 진행
    while(l_dist <= r_dist){

        // 설치한 공유기 개수 (첫 번째 공유기는 설치하고 시작)
        int install_router = 1;

        // 기준 간격 갱신
        int mid_dist = (l_dist + r_dist) / 2;

        // 첫번째 공유기 위치
        int start = router[0];

        // 각 공유기의 간격 확인
        for(int i = 1 ; i < n ; i++){

            // 간격 확인할 공유기 위치
            int end = router[i];

            // 공유기 간격이 기준 간격을 넘는지 확인한 뒤, 넘는 간격에는 공유기를 설치하고
            // 해당 위치를 다시 탐색 시작 위치로 변경
            if(end - start >= mid_dist){
                install_router ++;
                start = end;
            }
        }

        // 공유기 간격 탐색이 끝난 뒤, 설치한 공유기 개수가 C개 이상이라면
        if(install_router >= c){
            // 공유기 설치에 사용된 간격을 결과 간격으로 임시 저장
            result_dist = max(result_dist, mid_dist);
            // 이분법을 사용한 간격 갱신 시, 이전보다 넓은 간격을 사용하기 위해 L 수정
            l_dist = mid_dist + 1;
        }
        // 설치한 공유기 개수가 C개 미만이라면
        else {
            // 이분법을 사용한 간격 갱신 시, 이전보다 좁은 간격을 사용하기 위해, R 수정
            r_dist = mid_dist - 1;
        }
    }
    // 결과 거리 반환
    return result_dist;
}
int main(void){

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    // 공유기 개수, 설치 개수
    int n, c;
    cin >> n >> c;

    // 공유기 위치 입력
    int loc;
    for(int i = 0 ; i< n ; ++i){
        cin >> loc;
        router.push_back(loc);
    }

    // 공유기 위치 정렬
    sort(router.begin(), router.end());

    // 공유기 간 최대 거리 탐색 함수 실행
    cout << find_max_dist(n, c) << "\n";

    return 0;
}