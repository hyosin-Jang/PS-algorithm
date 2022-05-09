#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, b;

vector<int> flattenLand(vector<vector<int>>& field, int minHeight, int maxHeight) {
	int time = 99999999, height = 0;
	vector <int> answer(2);

	for (int curHeight = maxHeight; curHeight >= minHeight; curHeight--) { // h: 높이
		int cnt1 = 0, cnt2 = 0, cur_time = 0, tmp_b=0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (field[i][j] < curHeight) cnt1 += curHeight - field[i][j]; // 인벤토리에서 꺼내와서 쌓는 경우
				else cnt2 += field[i][j] - curHeight; // 인벤토리에 넣는 경우
			}
		}
		if (cnt1 <= b + cnt2) {
			cur_time = cnt1 + cnt2 * 2;
			if (cur_time < time) {
				time = cur_time;
				height = curHeight;
			}
		}
	}

	answer[0] = time;
	answer[1] = height;

	return answer;
}

int main() {
	cin >> n >> m >> b;
	vector<vector<int>> field(n + 1, vector<int>(m, 0)); // 0으로 초기화
	int minHeight = 300, maxHeight = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> field[i][j];
			minHeight = min(minHeight, field[i][j]);
			maxHeight = max(maxHeight, field[i][j]);
		}
	}
	vector<int> answer = flattenLand(field, minHeight, maxHeight);
	cout << answer[0] << ' ' << answer[1];

	return 0;
}
