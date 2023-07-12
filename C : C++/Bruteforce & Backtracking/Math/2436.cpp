#include <iostream>

using namespace std;

// 최대공약수 리턴
int gcdIter(int a, int b) {
	if (a < b) swap(a, b);
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int a, b;

	cin >> a >> b; // a를 최대공약수로 하고, b를 최소공배수로 하는 두 자연수
	int num = b / a;
	int di;

	for (int i = 1 ; i * i <= num; i++) {
		if (num % i == 0) {
			if (gcdIter(i, num / i) == 1) {
				di = i;
			}
		}
	}
	cout << a * di << " " << a * (num/ di) << "\n";
	
	return 0;
}
