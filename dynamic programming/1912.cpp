#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100000;
int N, tmp, maxResult;
int arr[MAX];
int main() {
	cin >> N;
	
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	
	maxResult = arr[0];

	for (int i = 1; i < N; i++) {
		tmp = arr[i - 1] + arr[i];
		if (tmp > arr[i]) // tmp가 자기자신보다 크다면
			arr[i] = tmp;
		maxResult = max(maxResult, arr[i]);
	}
	
	cout << maxResult << endl;
	return 0;
}
