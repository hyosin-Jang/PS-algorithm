#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int prime = 0;
// 소수판정법 정리하기
void isPrimeNumber(int k) {
	if (k == 1)
		return;
	for (int i = 2; i*i<=k ; i++)
		// k/2에서 루트 k까지로 수정
		if (k % i == 0) // k가 i의 배수라면
			return;
	prime++;
}

int main() {
	// 에라토스테네스의 체

	int n, num;
	cin >> n;

	for (int i = 0; i < n ; i++) {
		cin >> num;
		isPrimeNumber(num);
	}


	cout << prime;

	return 0;
}
