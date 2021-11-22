#include <iostream>
#include <deque>

using namespace std;
typedef pair<int,int> card;
deque <card> dq;
int N, tmp;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> tmp;
		dq.emplace_back(i, tmp);
	}

	// 3 2 1 -3 -1
	while (!dq.empty()) {
		
		card tmp = dq.front();
		cout << tmp.first << " ";

		dq.pop_front();
		for (int i = 1; i < tmp.second; i++) {
			dq.push_back(dq.front());
			dq.pop_front();
		}
		for (int i = 0; i > tmp.second; i--) {
			dq.push_front(dq.back());
			dq.pop_back();
		}
	}

	return 0;
}
