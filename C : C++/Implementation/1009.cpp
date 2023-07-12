#include <iostream>
using namespace std;


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t, a, b;
	cin >> t;

	while (t--) {
		int units = 1;
		cin >> a >> b;
		// 공백, 개행 무시
		// 개행=> 키보드 버퍼에 남겨둠

		// 일의 자리 숫자 구하기
		for (int i = 0; i < b; i++) {
			units *= a;
			units %= 10;
		}
		if (units == 0)
			cout << "10\n";
		else cout << units << "\n";
	}
	return 0;
}
