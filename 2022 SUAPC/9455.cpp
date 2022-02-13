#include <iostream>
using namespace std;

const int MAX = 101;

int arr[MAX][MAX];
int T;
int m, n;
int main() {

	cin >> T;

	while (T--) {
		// m행 n열
		int ans = 0;
		cin >> m >> n;

		for (int i = 0; i < m;i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}

		for (int j = 0; j < n; j++) {
			int cnt = 0;
			for (int i = m - 1; i >= 0; i--) {
				//cout << "i:" << i << "j:" << j << "\n";
				//cout << arr[i][j] << "\n";
				if (arr[i][j] == 1) {
					ans += (m - 1 - i - cnt);
					cnt++;
				}
				//cout << "j: " << j << "cnt:" << cnt << "ans: " << ans << "\n";
			}
		}

		cout << ans << "\n";
	
	}


	return 0;
}
