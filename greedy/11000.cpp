#include <iostream>
#include <vector>
#include <queue> // 우선순위 큐
#include <algorithm> // 정렬

using namespace std;

typedef pair<int, int> ci;
// 강의실 수를 최소로 하기 위해서, 가장 효율적으로 공간을 활용하기 위해 (강의실이 빈 시간대를 최소로 하기 위해)
// 현재 사용하는 강의실 중 가장 빨리 끝나는 강의실에 가장 먼저 시작하는 강의를 배치한다.
// 먼저 시작하는 순서로 정렬한다.
// 사용하는 강의실 중 현재 가장 빨리 끝나는 시간을 구하기 위해 최소 힙(우선순위 큐)를 사용함

int arrayRoom(int n, vector<ci> lec) {
	priority_queue<int, vector<int>, greater<>> pq; // 강의실의 종료시간을 저장하는 우선순위 큐

	pq.push(-1); // 처음 인덱스 에러 피하기 위해 음수 삽입

	for (int i = 0 ; i < n ; i++) {
		if (lec[i].first >= pq.top()) { // 같은 강의실 쓰는 경우
			pq.pop();
		}
		pq.push(lec[i].second); // 기존 강의실 정보가 갱신되거나 or 새로운 강의실 정보가 저장됨
	}

	return pq.size(); // 최소힙 노드의 개수 = 강의실의 개수
}

int main() {
	int n;

	cin >> n;

	vector<ci> lec(n, ci(0, 0));
	for (int i = 0; i < n;i++) {
		cin >> lec[i].first >> lec[i].second; // first: 시작시간, second: 종료시간
	}

	// 연산, 디폴트가 오름차순
	sort(lec.begin(), lec.end());

	cout << arrayRoom(n, lec) << '\n';

	return 0;
}
