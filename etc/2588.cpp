#include <iostream>
using namespace std;

int main() {
	// 둘 다 배열로 받을 필요가 없었던 문제
	
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int a;
	char b[4];

	cin >> a;
	cin >> b;

	cout << a * (b[2] - '0') << '\n';
	cout << a * (b[1] - '0') << '\n';
	cout << a * (b[0] - '0') << '\n';
	cout << a * atoi(b) << "\n";

	return 0;
}