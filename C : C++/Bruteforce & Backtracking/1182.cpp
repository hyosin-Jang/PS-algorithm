#include <iostream>
using namespace std;

int N, S, answer = 0;
int arr[21];

int new_arr[21];
bool visited[21];

// 조합
void dfs(int cur, int cnt, int depth) {
	if (cnt == depth) { 
		int sum = 0;
		for (int i = 0; i < depth; i++) sum += new_arr[i];
		if (sum == S) answer++;
		return;
	}

	for (int i = cur; i < N; i++) {
		if (visited[i] != true) {
			visited[i] = true; // 방문 표시
			new_arr[cnt] = arr[i];
			dfs(i+1, cnt + 1, depth);
			visited[i] = false;
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> S;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for(int i=1 ; i<=N ; i++)
		dfs(0, 0, i);

	cout << answer << "\n";
	return 0;
}
