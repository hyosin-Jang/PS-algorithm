#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 내림차순 정렬하는 함수
bool cmp(char a, char b) {
	if (a > b)
		return true;
	return false;
}

int main() {
	string N;
	cin >> N;

	long long sum = 0;

	// 10의 배수니까 반드시 0이 있어야 함
	bool zero = false;

	for (int i = 0; i < N.size(); i++) {
		sum += (N[i] - '0');
		if (!(N[i] - '0'))
			zero = true;

	}
	if (sum % 3 || !zero)
		cout << -1 << "\n";
	else {
		sort(N.begin(), N.end(), cmp);
		cout << N << "\n";
	
	}
	return 0;
}
