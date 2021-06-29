#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

// 기본 아이디어
//1. 양수를 오름차순으로 저장하는 pq1 생성
//   음수를 내림차순으로 저장하는 pq2 생성
//   (절댓값이 작은 수가 우선순위가 높기 때문)
//2. x 입력 받기
//3. x가 0이라면, 절댓값이 가장 작은 값 출력 및 제거
//4. 0이 아니라면, 배열에 x추가


int N, x;
priority_queue <int, vector<int>, greater<int>> pq1; // 양수 오름차순 저장
priority_queue <int> pq2; // 음수 내림차순 저장

int main() {
	//C++ 표준 스트림들이 C 표준 스트림들과 각각의 입출력 연산 후에 동기화 할지 여부를 설정
	ios_base::sync_with_stdio(0);
	
	// cin의 속도를 빠르게 하기 위해서 최적화해주는 구문
	cin.tie(0); 
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		if (x == 0) {
			// 둘다 비어있다면, 0출력
			if (pq1.empty() && pq2.empty()) cout << "0\n";

			else // 둘중 하나가 비어있거나 둘 다 원소가 있다면
			{
				if (pq1.empty()) {
					cout << pq2.top() << '\n';
					// 맨 앞에 있는 원소 반환(음수 중 절댓값 가장 작은 것)
					pq2.pop(); 
				}
				else if (pq2.empty()) {
					cout << pq1.top() << '\n';
					pq1.pop();
				}
				else {
					// 둘 다 원소가 있다면, 더 작은 값 출력
					if (pq1.top() < -pq2.top()) {
						cout << pq1.top() << '\n';
						pq1.pop();
					}
					else {
						cout << pq2.top() << '\n';
						pq2.pop();

					}
				}
			}
		}
		else if (x > 0) 
			pq1.push(x);
		else
			pq2.push(x);
	}
}