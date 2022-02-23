#include <iostream>
#include <algorithm>
using namespace std;

int N, S;
int arr[100001];
int cur_sum, len= 999999;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> S;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int i = 0, j=0;
	cur_sum = arr[0];

	while (1) {
		while (cur_sum < S && i<N) {
			cur_sum += arr[++i];
		}
		while (cur_sum >= S && j<=i) {
			len = min(len, i - j + 1);
			cur_sum -= arr[j++];
		}
		if (i >= N - 1)
			break;
	}


	if (len == 999999)
		cout << "0\n";
	else	
		cout << len << endl;


	return 0;
}
