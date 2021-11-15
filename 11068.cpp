#include <iostream>
using namespace std;

int arr[20];

int main() {
	int T;
	cin >> T;
	
	while (T--) {
		int num, breakflag = 0;
		cin >> num;
		for (int i = 2; i <= 64; i++) {
			int quote = num; 
			int j = 0, flag=1;
			while (quote >= i) {	
				arr[j++] = quote % i;
				quote = quote / i;
			}
			arr[j] = quote;

			for (int l = 0; l <= j / 2; l++) {
				if (arr[l] == arr[j - l])
					continue;
				else
					flag = 0; break;
			}
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