#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

vector <int> v;
int main() {
	int n, m, tmp,d, f=1, r=0;
	cin >> n;
	cin >> m;

	
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}

	// 내림차순
	sort(v.begin(), v.end(), greater<int>());
	

	for (int i = 0; i < n-1; i++) {
		d = v[i] - v[i+1];

		if (d*f >= m) {
			r += m / f;
			printf("%d", v[0]-r);
			break;
		}

		m -= d * f; // m=3
		f += 1; // f=2
		r += d;
	}

	return 0;
}
