#include <iostream>
using namespace std;
const int MAX = 9;

// dfs로 조합 구하기
int arr[MAX] = {0, };
int visited[MAX] = { 0, };
int N, M;

void dfs(int cnt) { // 현재 위치
	if (cnt == M) {
		for (int i = 0; i < M; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;	
	}
	// for문 한번씩 돌때마다 한줄씩 출력
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			// visited[i] = true; // 방문했다고 표시하기
			arr[cnt] = i;
			dfs(cnt + 1); // cnt +1 까지 더 깊게 들어가자
			visited[i] = false;
		}
	}
}

int main() {

	cin >> N >> M;
	dfs(0);

	return 0;
}
