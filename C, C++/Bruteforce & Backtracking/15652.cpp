#include <iostream>
using namespace std;
const int MAX = 9;

int arr[MAX] = {0, };
int N, M;
bool visited[MAX] = { 0, };

void dfs(int num, int cnt) { // 현재 위치
	if (cnt == M) {
		for (int i = 0; i < M; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;	
	}
	// for문 한번씩 돌때마다 한줄씩 출력
	for (int i = num; i <= N; i++) {
			visited[i] = true;
		    arr[cnt] = i;
			dfs(i, cnt + 1); // cnt +1 까지 더 깊게 들어가자
			visited[i] = false;
	}
}

int main() {

	cin >> N >> M;
	dfs(1, 0);

	return 0;
}
