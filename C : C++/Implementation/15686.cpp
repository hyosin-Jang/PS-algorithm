#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int Answer;

const int MAX = 51;
int N, M, Chicken_num;
int arr[MAX][MAX];
bool Select[13];

// V는 chicken 중에서 M개 고르는데 선택된 치킨집 인덱스
vector <pair<int, int>> House, Chicken, V;

int Calculate_distance() {
	int Sum = 0;

	// 집이 담겨 있는 벡터를 돌면서
	for (int i = 0; i < House.size(); i++) {
		int x = House[i].first;
		int y = House[i].second;
		int d = 99999999;

		// 각 집에서 가장 가까이 있는 V를 고름
		for (int j = 0; j < V.size(); j++) {
			int xx = V[j].first;
			int yy = V[j].second;
			int Dist = abs(xx - x) + abs(yy - y);

			d = min(d, Dist);
		}
		Sum += d;
	}

	// Sum: V들로 이루어진 벡터에서 도시의 최단 거리
	return Sum;

}

// idx: 치킨 넘버 세는 인덱스
void Select_chicken(int idx, int cnt) {
	if (cnt == M) {
		Answer = min(Answer, Calculate_distance());
		return;
	}
	for (int i = idx; i < Chicken_num; i++) {
		if (Select[i] == true) continue;

		// select[i]가 false라면
		Select[i] = true;
		V.push_back(Chicken[i]);

		// i부터 시작해서 백트래킹으로 M개를 셈
		Select_chicken(i, cnt + 1);
		Select[i] = false;
		V.pop_back();
	}
}

void Solution() {
	Select_chicken(0, 0);
	cout << Answer << endl;
}


void Input() {

	Answer = 99999999;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) // 치킨집이면
				Chicken.push_back(make_pair(i, j));
			if (arr[i][j] == 1) // 집이면
				House.push_back(make_pair(i, j));
		}
	}
	Chicken_num = Chicken.size();

}

void Solve() {

	Input();
	Solution();
	
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Solve();

	return 0;
}
