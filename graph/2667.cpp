#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N, cnt=0;
string map[26];
vector<int> p;

// 오른쪽, 왼쪽, 위, 아래
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

void dfs(int x, int y) {

	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N) 
			continue;

		if (map[next_x][next_y] == '1') {
			cnt++;

			map[next_x][next_y] = '2';
			dfs(next_x, next_y);
		}
	}

}
int main() {

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> map[i];
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == '1') {
				cnt = 1;
				map[i][j] = '2';
				dfs(i, j);
				p.push_back(cnt);
			}
		}
	}

	cout << p.size() << endl;

	sort(p.begin(), p.end());

	for (int i = 0; i < p.size(); i++) 
		cout << p[i] << endl;

	return 0;
}