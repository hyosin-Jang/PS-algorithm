#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <pair<string, int>> v;
int n;
string a;
int b;
int idx;
int max_num = 0;

bool compare(pair <string, int>p1, pair <string, int>p2) {

	// y 좌표가 같다면 
	if (p1.second == p2.second) {
		// 이름이 앞선 사람
		return p1.first < p2.first; 
	}
	return p1.second > p2.second;
}

int main() {
	cin >> n;

	for (int i = 0; i < n;i++) {
		cin >> a >> b;
		if (max_num < b) {
			max_num = b;
			idx = i;
		}

		v.push_back(make_pair(a, b));
	
	
	}
	// v를 b 내림차순으로 정렬
	sort(v.begin(), v.end(), compare);

	cout << v[0].first << endl;

	return 0;
}
