#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector <int> v;
int main() {
	int N, tmp, result=0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	// 10 20 30 50
	sort(v.begin(), v.end(), less<int>());
	for (int i = 0; i < N; i++) {
		tmp = v[i] * (N - i);
		result = max(tmp, result);
	}
	cout << result;
	return 0;
}