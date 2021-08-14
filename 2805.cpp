#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <int> v;
int main() {
	int n, m, d, f=1, result=0;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
		cin >> v[i];

	// 내림차순
	sort(v.begin(), v.end(), greater<int>());
	
	for (int i = 0; i < n-1; i++) {
		d = v[i] - v[i+1];
		if ((result+d*f) >= m) {
			result = v[0]-result+(m - result) / f;
			break;
		}
		result += d * f;
		f += 1;
	}
	cout << result;

	return 0;
}