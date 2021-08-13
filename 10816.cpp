#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, num, M, cnt;
	cin >> N;

	vector <int> v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];
	
	sort(v.begin(), v.end());
	cin >> M;

	// ÀÌÁø Å½»ö
	for (int i = 0; i < M; i++) {
		cin >> num;
		cout << upper_bound(v.begin(), v.end(), num) - lower_bound(v.begin(), v.end(), num) << " ";
	
	}

	cout << "\n";

	return 0;

}