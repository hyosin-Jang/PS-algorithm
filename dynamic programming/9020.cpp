#include <iostream>
#include <cmath>
using namespace std;

int isPrime(int i) {
	int rt;
	rt = sqrt(i); // i의 제곱근
	if (rt == 1 && i != 1)
		return 1; // 2, 3인 경우
	if (i % 2) { // 제곱근까지만 검사
		for (int j = 2; j <= rt; j++) {
			if (!(i % j))
				return 0;
			if (j == rt)
				return true;
		}
	}
}

int main() {
	int T=0, n;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;

		// n의 중앙값부터 2까지 감소시키며 두 수 모두 소수인지를 검사
		for (int i = n / 2; i >= 2; i--) {
			if (isPrime(i) && isPrime(n - i)) {
				cout << i << " " << n-i << '\n';
					break;
			}
		}
	}

}