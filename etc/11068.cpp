#include <iostream>
using namespace std;

int arr[20];

// 회문인 수인지 체크하는 함수
int checkPalindrome(int length) {
	int flag = 1;

	for (int l = 0; l <= length / 2; l++) {
		if (arr[l] == arr[length - l])
			continue;
		else
			flag = 0; break;
	}
	return flag;

}


int main() {
	int T;
	cin >> T;
	
	while (T--) {
		int num, breakflag = 0;
		cin >> num;

		for (int i = 2; i <= 64; i++) {
			int quote = num, j = 0;

			while (quote >= i) {	
				arr[j++] = quote % i;
				quote = quote / i;
			}
			arr[j] = quote;

			int flag = checkPalindrome(j);

			if (flag == 1) {
				cout << flag << "\n"; 
				breakflag = 1; break;
			}

		}
		if(breakflag==0)
			cout <<  "0\n";	
	}
	return 0;
}
