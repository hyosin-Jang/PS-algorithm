#include <iostream>

using namespace std;
int arr[10] = {0};
int rem[42]; // 나머지 저장
int main() {
	int tmp,cnt=0;
	for (int i = 0; i < 10; i++) {
		cin >> tmp;
		arr[i] = tmp % 42; //42로 나눈 나머지
	}
	// 1 2 3 4 5 6 1 1 9 1

	for (int i = 0; i < 10; i++) {
		tmp = arr[i]; // 1
		arr[tmp] ++;
	}

	for (int i = 0; i < 42; i++) {
		if (arr[i] == 1)
			cnt++;
	}
	cout << cnt;

	return 0;
}