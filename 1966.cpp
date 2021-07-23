#include <iostream>
#include <algorithm>
# include <queue>
# include <stack>
using namespace std;

int main() {
	int T, N, M, temp;
	cin >> T;
	while (T--) {
		int cnt = 0;

		cin >> N >> M;	
		queue <pair<int, int>> q;
		priority_queue <int> pq;

		for (int i = 0; i < N; i++) {
			cin >> temp;
			q.push({ i,temp });
			pq.push(temp);
		}
		while (!q.empty()) {
			int idx = q.front().first; // index 값
			int val = q.front().second; // 중요도 값
			q.pop();
			if (pq.top() == val) {
				pq.pop();
				cnt++;
				if (idx == M) {
					cout << cnt << endl;
					break;
				}
			}
			else
				q.push({ idx, val });
			
		}	
	}
	return 0;
}