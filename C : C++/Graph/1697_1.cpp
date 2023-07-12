#include <iostream>
#include <queue>
using namespace std;

const int MAX = 100000+1;

int N, K;
int visited[MAX] = {0, };
int cnt = 0, loc, transfer;
queue <pair<int, int>> Q;

void BFS() {
	Q.push(make_pair(N, 0));
	visited[N] = 1;

	while (!Q.empty()) {
		loc = Q.front().first;
		cnt = Q.front().second;
		Q.pop();

		// 정지 조건
		if (loc == K) {
			cout << cnt << "\n";
			return;
		}
		cnt++;

		transfer = loc * 2;

		if (loc + 1 < MAX && !visited[loc + 1]) {
			Q.push(make_pair(loc + 1, cnt));
			visited[loc + 1] = 1;
		}
		if (loc -1 >= 0 && !visited[loc - 1]) {
			Q.push(make_pair(loc - 1, cnt));
			visited[loc - 1] = 1;
		}
		if (transfer <= MAX && !visited[transfer]) {
			Q.push(make_pair(loc * 2, cnt));
			visited[loc * 2] = 1;
		}
	}
}

int main() {

	cin >> N >> K;
	if (K < N)
		cout << N - K;
	else {
		BFS();
	}
	return 0;
}
