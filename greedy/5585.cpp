#include <iostream>

using namespace std;

int main() {
	int input, change, cnt=0;
	int arr[6] = { 500,100,50,10,5,1 };
	cin >> input;

	change = 1000 - input;
	while (change) {
		for (int i = 0; i < 6; i++) {
			cnt += change / arr[i];
			change %= arr[i];
		}

	}
	cout << cnt << endl;

	return 0;
}