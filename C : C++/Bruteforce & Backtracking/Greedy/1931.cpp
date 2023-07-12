#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <pair<int, int>> v;

bool compare(pair <int, int> p1, pair <int, int> p2) {
	if (p1.second == p2.second) {
		return p1.first < p2.first;
	}
	else
		return p1.second < p2.second;
}

int main() {
	int N, start, end, cnt=0, now=-1;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> v[i].first >> v[i].second;
		

	// end 기준 오름차순 정렬하기
	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < N; i++) 
		if (v[i].first >= now) {
			now = v[i].second;
			cnt++;
		}
	

	cout << cnt << endl;

	return 0;
}
