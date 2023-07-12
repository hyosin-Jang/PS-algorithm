#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, num, minNum=1000001, maxNum=1;
	cin >> n;
	for (int i = 0; i < n;i++) {
		cin >> num;
		minNum = min(num, minNum);
		maxNum = max(num, maxNum);
	}

	cout << minNum * maxNum;

}
