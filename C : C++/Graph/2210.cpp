#include <iostream>
#include <string>
#include <set> 
using namespace std;

set <string> s; // 중복 제거하므로 set 사용
int arr[6][6];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void dfs(int r, int c, string str) {
	if (str.length() == 6) {
		s.insert(str); // set에 문자열 담기
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = r + dx[i];
		int ny = c + dy[i];
		if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5) {
			dfs(nx, ny, str + to_string(arr[nx][ny]));
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			dfs(i, j, to_string(arr[i][j]));
		}
	}
	cout << s.size() << "\n";
}
