#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, cnt=0;
	int arr[250];
	cin >> n;

	for (int i = 0; i * i <= 50000; i++)
		arr[i] = i * i;

	// 수를 한개만 더해서 n 되나 체크
	for (int i = 1; i * i <= n; i++)
		if (arr[i] == n) {
			cout << i << "\n";
			cout << "1\n"; return 0;
		}
	// 수 두개 더해서 n되나 체크
	for (int i = 1; i * i <= n -1; i++) {
		for (int j = i + 1; j * j <= n; j++) {
			if (arr[i] + arr[j] == n) {
				cout << "2\n";
				cout << i << " " << j << "\n";
				return 0;
			}
		}
	}

	// 수 세개 더해서 n되나 체크
	for (int i = 1; i * i <= n - 2; i++) {
		for (int j = i + 1; j * j <= n -1; j++) {
			for (int k = j + 1; k * k <= n; k++) {
				if (arr[i] + arr[j] + arr[k] == n) {
					cout << "3\n";
					cout << i << " " << j << " " << k << "\n";
					return 0;
				}
			}
		}
	}

// 1 4 9 16 25 36 49 64
	// 1 9 16 25
	// 26 }+ 25 
	// 51
	// 수 네 개 더해서 n되나 체크
	for (int i = 1; i * i <= n - 3; i++) {
		for (int j = i + 1; j * j <= n - 2; j++) {
			for (int k = j + 1; k * k <= n - 1; k++) {
				for (int l = k + 1; l * l <= n ; l++) {
					if (arr[i] + arr[j] + arr[k] + arr[l] == n) {
						cout << "4\n";
						cout << i << " " << j << " " << k << " " << l << "\n";
						return 0;
					}
				}
			}
		}
	}


	return 0;
}
