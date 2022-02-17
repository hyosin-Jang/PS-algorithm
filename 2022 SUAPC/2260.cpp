#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

vector <int> v[51];
vector <int> president;

int N, f1, f2;

int score[51]; // 최고 점수 저장하는 배열
int minNum[51]; // 가장 작은 점수를 가진 친구의 인덱스를 저장
int visited[51];

int min_score = 100000;
int president_cnt;


int BFS(int num) {

	int max_depth = 0;

	memset(visited, 0, sizeof(visited));

	queue <pair<int, int>> q; // 점수, 인덱스 저장

	q.push(make_pair(num, 0));

	visited[num] = 1;

	while (!q.empty()) {
		int f = q.front().first; 
		int d = q.front().second; // 깊이
		max_depth = max(max_depth, d);

		q.pop();

		for (int i = 0; i < v[f].size(); i++) {
			int next = v[f][i];

			if (visited[next] == 0) {
				visited[next] = 1;

				q.push(make_pair(next, d + 1));
			
			}
	
		}

	}
	return max_depth;

}


int main() {

	cin >> N;

	while(1){
		cin >> f1 >> f2;

		if (f1 == -1 && f2 == -1)
			break;
		v[f1].push_back(f2);
		v[f2].push_back(f1);
		// 1인 것들만 따로 저장해놓을까???
	}


	for (int i = 1; i <= N; i++) {

		// BFS로 점수 계산
		score[i] = BFS(i);

		// 점수 작으면 갱신하기
		if (score[i] < min_score) {
			min_score = score[i];
			president_cnt = 1;
			president.clear();

			president.push_back(i);
		}
		// 점수 같으면 추가하기
		else if (score[i] == min_score) {
			president.push_back(i);
			president_cnt++;
			
		}
	}

	// 회장 후보 점수, 후보 수
	cout << min_score << ' ' << president.size() << endl;

	// 회장 후보
	for (int i = 0; i < president.size(); i++) {
		cout << president[i] << ' ';
	}



	return 0;
}
