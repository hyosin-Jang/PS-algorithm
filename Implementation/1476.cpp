#include <iostream>
using namespace std;

int E, S, M;
int main() {
	cin >> E >> S >> M;

	// E, S, M이 각각 15, 28, 19의 배수인 경우
	// 나머지가 0이므로 미리 0으로 초기화해 줌
	if (E == 15) E = 0;
	if (S == 28) S = 0;
	if (M == 19) M = 0;

	for (int i = 1; i < 7981; i++) {
	
		if (i % 15 == E && i % 28 == S && i % 19 == M) {
			cout << i;
			break;
		}
	}

	return 0;
}
