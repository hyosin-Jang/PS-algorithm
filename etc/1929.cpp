#include<iostream>
#include <cmath>
using namespace std;

// �����佺�׳׽��� ü �̿�
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
			// i�� �Ҽ���� i�� ��� �����
			for (int j = i * 2; j <= N; j += i)
				prime[j] = false;
	for (int i = M; i <= N; i++)
		if (prime[i] == true)
			cout << i << '\n';

	return 0;
}