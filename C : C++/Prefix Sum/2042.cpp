#include <iostream>
#include <map>
using namespace std;

int p_sum[1000001];
int N, K, M, num, a, b, c;
long long answer = 0;
int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N  >> M >> K;

	for (int i = 1; i <= N; i++) {
		cin >> num;
		p_sum[i] = p_sum[i - 1] + num;
	}
	int T = M + K;

	while (T --) {
		cin >> a >> b >> c;
		if (a == 1) {
			int tmp = c - (p_sum[b] - p_sum[b - 1]);
			for (int i = b; i <= N; i++)
				p_sum[i] += tmp;
		}
		else {
			cout << p_sum[c] - p_sum[b - 1] << "\n";
		}
	}
	


	return 0;
}
