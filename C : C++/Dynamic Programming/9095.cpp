#include <iostream>
#include <vector>
using namespace std;

int main() {

	int N, T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N;
		int arr[11] = { 0 };
		arr[1] = 1;
		arr[2] = 2;
		arr[3] = 4;
		for (int j = 4; j <= N; j++)
			arr[j] = arr[j - 3] + arr[j - 2] + arr[j-1];
		cout << arr[N] << endl;
	}
	return 0;
}