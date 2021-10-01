#include <stdio.h>
#include <algorithm>
#include <math.h> 

using namespace std;

int main() {

	int n;
	scanf("%d", &n);

	double arr[1010];

	for (int i = 0; i < n; i++)
		scanf("%lf", &arr[i]);

	sort(arr, arr + n);

	double max = arr[n - 1];

	for (int i = 0; i < n; i++) {
		arr[i] = round(arr[i] / max * 100 * 100) / 100;
	}

	double sum = 0;

	for (int i = 0; i < n; i++)
		sum += arr[i];

	double result = sum / n;

	result = round(result * 1000000) / 1000000;

	printf("%lf", result);

	return 0;
}
