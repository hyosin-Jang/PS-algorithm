#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 300000;
pair<int, int> jewerly[MAX];
int bag_max_weight[MAX];

priority_queue<int> pq;

int main() {
	int N, K;
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> K;

	for (int i = 0; i < N; i++)
		cin >> jewerly->first >> jewerly->second;
	
	for (int i = 0; i < K; i++)
		cin >> bag_max_weight[i];

	// 보석 (무게 기준)과 가방 오름차순 정렬
	sort(jewerly, jewerly + N);
	sort(bag_max_weight, bag_max_weight + K);

	long long result = 0;
	int idx = 0;

	// 무게제한이 낮은 가방부터 최대한 비싼 보석을 넣는다
	for (int i = 0; i < K; i++) // 가방 개수만큼 반복문 돌리기
	{
		//i번째 가방의 무게제한에 충족하는 보석의 가격을 pq에 다 넣음
		while (idx < N && jewerly[idx].first <= bag_max_weight[i])
			pq.push(jewerly[idx++].second);

		// 우선순위 큐는 maxHeap이므로 루트에 가장 비싼 보석이 들어있음
		if (!pq.empty()){
			result += pq.top();
			pq.pop();
		}
	}

	cout << result << endl;

	return 0;
}
