#include <iostream>
#include <cstdio>
using namespace std;

int N;

double sum;
double arr[100001];

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];

		// 일반 전구가 켜지는 모든 기댓값
		sum += arr[i]; 
	}

	// 추가 전구의 기댓값
	for (int i = 1; i < N ; i++) {
		sum += (arr[i] * (1 - arr[i - 1]) + (1 - arr[i]) * arr[i - 1]);
	}


	printf("%.7lf", sum);



	return 0;
}
