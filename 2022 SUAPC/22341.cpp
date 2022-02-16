#include <iostream>
#include <vector>
using namespace std;

int n, c;

int a, b;
vector <pair<int, int>> v;




int main() {


	int x, y;

	cin >> n >> c;
	a = b = n;
	for (int i = 0; i < c; i++) {
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}

	// c개의 점에 대해 체크
	for (int i = 0;i < c;i++) {
		if (v[i].first >= a || v[i].second >= b)
			continue;

		else {

			// 세로 > 가로
			if (a * v[i].second > v[i].first * b) {
				b = v[i].second;
			}
			// 세로 == 가로, 세로 < 가로
			else {
				a = v[i].first;
			}
		}

	}

	cout << a * b << endl;


	return 0;
}
