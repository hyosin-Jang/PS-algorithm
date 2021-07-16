#include<iostream>
#include <cmath>
using namespace std;

// 에라토스테네스의 체 이용
int main() {
	int M, N;
	bool* prime;
	cin >> M;
	cin >> N;
	prime = new bool[N + 1];
	fill_n(prime, N + 1, 1);
	prime[0] = false;
	prime[1] = false;

	for (int i = 2; i <= sqrt(N); i++)
		if (prime[i] == true)
			// i가 소수라면 i의 배수 지우기
			for (int j = i * 2; j <= N; j += i)
				prime[j] = false;
	for (int i = M; i <= N; i++)
		if (prime[i] == true)
			cout << i << '\n';

	return 0;
}