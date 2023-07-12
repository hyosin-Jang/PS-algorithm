#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;


int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	double x, y, c;
	cin >> x >> y >> c;

	double l = 0, r = max(x, y), mid;
	double tmp, result=0;

	while (r - l > 0.000001) {
		mid = (l + r) / 2.0;
		tmp = (sqrt(x * x - mid * mid) * sqrt(y * y - mid * mid)) / (sqrt(y * y - mid * mid) + sqrt(x * x - mid * mid));
		if (tmp >= c) {
			result = mid;
			l = mid;
		}
		else r = mid;
	}

	printf("%.3lf", result);
	return 0;
}
