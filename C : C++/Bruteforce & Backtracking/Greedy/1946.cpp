#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 1000000;

pair<int, int> v[MAX];
int main() {
	int T, num;
	cin >> T;

	while (T--) {
		cin >> num;

		for (int i = 0; i < num; i++)
			cin >> v[i].first >> v[i].second;
		sort(v, v+num);

		int result = 1; // 첫 번째 사원은 무조건 선발
		int r = v[0].second; // 첫 번째 사원의 인터뷰 성적

		for (int i = 1; i < num; i++) {
			if (v[i].second < r) {
				result++;
				r = v[i].second;
			}
		}
		cout << result << endl;
	
	}

	return 0;
}