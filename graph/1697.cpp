#include<iostream>
#include<algorithm>
#include<queue>
#include <cstdio>
#define MAX_VALUE 100001

using namespace std;

bool visit[MAX_VALUE];
int cnt = 0;

void dfs(int n, int k) {
	// 5 17
	queue <int> q;
	q.push(n);

	while (1) {
		int size = q.size();

		for (int i = 0; i < size; i++) {
			n = q.front();
			q.pop();

			if (n == k) {
				cout << cnt << endl;
				return;
			}
			// n-1 방문안한 곳이면 방문
			if (n > 0 && visit[n - 1] == 0) {
				q.push(n - 1);
				visit[n - 1] = 1;
			}
			// n+1 방문안한 곳이면 방문
			if (n < 100000 && visit[n + 1] == 0) {
				q.push(n + 1);
				visit[n + 1] = 1;
			}
			// 2*n 방문안한 곳이면 방문
			if (n * 2 <= 100000 && visit[2 * n] == 0) {
				q.push(n * 2);
				visit[n * 2] = 1;
			}
		}
		cnt++;
	}
}

int main() {
	int n, k;
	cin >> n >> k;

	dfs(n, k);

	return 0;
}