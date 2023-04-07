#include <iostream>
using namespace std;

/*
* 
* 나눗셈을 수학적으로 접근하는 문제
* 
  1. 처음 접근 방법
	(a/b)에 10^n을 곱해서 구하려는 숫자를 일의 자리 수로 만든 다음
    10으로 나눈 나머지를 구하면 일의 자리 숫자가 구하려는 숫자가 됨
   
   => N의 최댓값이 1,000,000이므로 메모리 문제 발생함

  2. 나눗셈을 수학적으로 접근
*/

int main() {
	int a, b, n;
	int res = 0;

	cin >> a >> b >> n;
	if (a % b == 0) {
		cout << 0;
		return 0;
	}

	if (a > b) a = a % b;

	for (int i = 0; i < n;i++) {
		a *= 10;
		res = (int)(a / b);
		a = a % b; 
	}

	cout << res;

	return 0;
}
