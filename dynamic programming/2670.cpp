#include <iostream>
#include <cstdio>
using namespace std;

double arr[10001];
double result = 0;

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	result = arr[0];

	for (int i = 1; i < n;i++) {
		if (arr[i] * arr[i - 1] >= arr[i])
			arr[i] = arr[i - 1] * arr[i];
		result = max(result, arr[i]);
	}

	printf("%.3lf", result);

	return 0;
}
