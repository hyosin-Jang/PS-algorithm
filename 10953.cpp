#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

int main() {
	int T;
	char str[4];
	cin >> T;
	while (T--) {
		int sum = 0;
		cin >> str;
		char* tok1 = strtok(str, ",");
		while (tok1 != NULL) {
			sum += atoi(tok1);
			tok1 = strtok(NULL, ",");
		}
		cout << sum << "\n";
	}


	return 0;
}
