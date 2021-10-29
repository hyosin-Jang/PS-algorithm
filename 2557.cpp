#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int T, result=0;
	int a, b;
	cin >> T;

	while (T--) {
		cin >> a >> b;
		if (b % 4 == 0)
			b = 4;
		else {
			b %= 4;
		}
		if (a % 10 == 0) {
			result = 10;
			cout << result<< "\n";
		}
		else {
			a %= 10;
			result = pow(a, b);
			cout << result % 10 << "\n";
		}
		
	}

	return 0;
}
