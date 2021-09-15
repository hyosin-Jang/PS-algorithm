#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long arr[91], n;
	arr[0] = 0;
	arr[1] = 1;
	
	cin >> n;

	for (int i = 2; i <= n; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	cout << arr[n];


	return 0;
}
