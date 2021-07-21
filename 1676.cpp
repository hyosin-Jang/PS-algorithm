#include<iostream>

#define min(a,b)(a< b ? a: b)
using namespace std;

int main() {
	int n, cnt = 0, tmp;
	cin >> n;

	int two = 0, five = 0;
	for (int i = 1; i <= n;i++) {
		tmp = i;
		while (tmp) {
			// 2의 개수 세기
			if (tmp % 2 == 0) {
				two++;
				tmp /= 2;
			}
			else
				break;
		}
		tmp = i;
		while (tmp) {
			// 5의 개수 세기
			if (tmp % 5 == 0) {
				five++;
				tmp /= 5;
			}
			else
				break;
		}

	}

	cout << min(two, five);
	return 0;
}
