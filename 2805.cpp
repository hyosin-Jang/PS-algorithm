#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>
using namespace std;

float n, m, tmp, d, f = 1, r = 0;
vector <float> v;
int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end(), greater<float>());
	
	for (int i = 0; i < n-1; i++) {
		d = v[i] - v[i+1];

		if (d*f >= m) {
			tmp = m / f;
			r += ceil(tmp);
			printf("%d", (int)(v[0]-r));
			break;
		}
			m -= d * f; // m=3
			f += 1; // f=2
			r += d;
	}

	return 0;
}
