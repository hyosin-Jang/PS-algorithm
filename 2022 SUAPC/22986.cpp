#include <iostream>
using namespace std;

int T;
long long N, K;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	while (T--) {
		cin >> N >> K;

		if (N - K - 1 < 0)
			cout << 2 * N * (N + 1) <<"\n";
		else
			cout << 2*N*(N+1) - 2*(N-K-1)*(N-K) << "\n";

	}


	return 0;
}
