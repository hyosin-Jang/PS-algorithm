#include <iostream>
using namespace std;

int Mushroom[11];
int sum=0;

int main() {

	for (int i = 0; i < 10; i++)
		cin >> Mushroom[i];

	for (int i = 0; i < 10; i++) {
		int tmp = sum + Mushroom[i];
		if (tmp >= 100) { // 뒤에꺼 더이상 못먹으므로 종료
			if (tmp - 100 <= 100 - sum)
				cout << tmp;
			else
				cout << sum;
			return 0;
		}
		sum = tmp;
	}

	// 100 못넘길 경우
	cout << sum << endl;
	

	return 0;
}
