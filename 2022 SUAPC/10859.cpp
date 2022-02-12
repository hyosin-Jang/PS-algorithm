#include <iostream>
#include <cmath>
using namespace std;

string input;
unsigned long long N=0, reverseN;

int isPrimeNumber(unsigned long long num) {

	if (num <= 1)
		return 0;

	if (num % 2 == 0)
		return num == 2 ? 1 : 0;

	for (int i = 3; i <= sqrt(num); i += 2) {
		if (num % i == 0)
			return 0;
	}
	return 1;
}

// 뒤집은 숫자 리턴
unsigned long long reverse(string str) {
	unsigned long long N=0; 
	for (int i = str.length() - 1; i >= 0; i--) {
		int tmp = str[str.length() - 1 - i] - '0';
		if (tmp == 3 || tmp == 4 || tmp == 7)
			return 0;
		else if (tmp == 9)
			tmp = 6;
		else if (tmp == 6)
			tmp = 9;
			
		N += (tmp * pow(10, str.length() - 1 - i));

	}

	return N;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> input;

	for (int i = input.length()-1; i >= 0; i--) {
		N += ((input[input.length() - 1 - i]-'0') * pow(10, i));
	}

	reverseN = reverse(input);

	if (reverseN == 0)
		cout << "no\n";
	else if (isPrimeNumber(N) && isPrimeNumber(reverseN))
		cout << "yes\n";
	else
		cout << "no\n";


	return 0;
}
