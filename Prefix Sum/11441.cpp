#include <iostream>
using namespace std;

int arr[100001], sum[100001];
int N, M, s, e;
int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 0; i < N; i++) {
		if (i == 0)
			sum[i] = arr[i];
		else 
			sum[i] = arr[i] + sum[i - 1];
	}

	cin >> M; 
	for (int i = 0; i < M; i++) {
		cin >> s >> e; 
		if (s==1)
			cout << sum[e - 1] << "\n";
		else
			cout << sum[e - 1] - sum[s - 2] << "\n";
	}

	return 0;
}
