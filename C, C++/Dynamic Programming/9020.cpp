#include <iostream>
#include <cmath>
using namespace std;

int isPrime(int i) {
	int rt;
	rt = sqrt(i); // i�� ������
	if (rt == 1 && i != 1)
		return 1; // 2, 3�� ���
	if (i % 2) { // �����ٱ����� �˻�
		for (int j = 2; j <= rt; j++) {
			if (!(i % j))
				return 0;
			if (j == rt)
				return true;
		}
	}
}

int main() {
	int T=0, n;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;

		// n�� �߾Ӱ����� 2���� ���ҽ�Ű�� �� �� ��� �Ҽ������� �˻�
		for (int i = n / 2; i >= 2; i--) {
			if (isPrime(i) && isPrime(n - i)) {
				cout << i << " " << n-i << '\n';
					break;
			}
		}
	}

}