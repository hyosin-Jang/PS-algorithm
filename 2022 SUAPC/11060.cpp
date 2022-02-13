#include <iostream>
#include <queue>
using namespace std;

int arr[1001];
int visit[1001];
int N;

int tmp, cnt;
// idx: 현재 위치
void BFS(int idx) {
	
	queue <pair<int, int>> q;

	visit[idx] = 1;
	// 현재 위치, 점프할 수 있는 칸수
	q.push(make_pair(idx, 0));

	while (!q.empty()) {
		// 현재 위치
		tmp = q.front().first;
		cnt = q.front().second;
		q.pop();

		//cout << "tmp: " << tmp << "\n";
		if (tmp == N-1) {
			cout << cnt << endl;
			return;
		}
		if (tmp > N-1)
			return;
		
		// 1 들어감
		for (int i = 1; i <= arr[tmp]; i++) {

			// 아직 방문하지 않았다면
			if (tmp + i < N && visit[tmp + i] != 1) {
				visit[tmp + i] = 1;
				q.push(make_pair(tmp + i, cnt + 1));
			}
		}
	}

	cout << -1 << endl;
	

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N;i++) 
		cin >> arr[i];
	
	BFS(0);
	
	return 0;
}
