#include <iostream>
#include <map>
using namespace std;

int p_sum[200001];
int N, K, num;
long long answer = 0;
int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> K;
	map<int, long long> m; // 부분합, 빈도

	m[0] = 1;
	for (int i = 1; i <= N; i++) {
		cin >> num;
		p_sum[i] = num + p_sum[i - 1];
		// i까지의 부분합에서 K를 뺀 값이 m에 존재한다면
		// answer에 m에 존재하는 값 더하기
		answer += m[p_sum[i] - K];
		m[p_sum[i]]++;
	}

	cout << answer << "\n";


	return 0;
}
