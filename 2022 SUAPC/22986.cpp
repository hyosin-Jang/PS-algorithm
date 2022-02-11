#include <iostream>
using namespace std;

int T;
long long N, K;
int main() {
	cin >> T;

	while (T--) {
		cin >> N >> K;
		int result = 0;
		int temp = K + 1;

		while (temp--) {
			result += (N--) * 4;
		}

		cout << result << endl;

	}


	return 0;
}
