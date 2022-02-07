#include <iostream>
#include <string>
using namespace std;

int T, N, K, tmp;
string s;
int word[101], cnt=1;

int checkisPalindrome() {

	for (int i = 0; i < N / 2; i++) {
		if (word[i] != word[N - i - 1]) {
			return 0;
		}
	}

	return 1;
}

int main() {

	cin >> T;

	while (T--) {
		cin >> N >> K;
		cin >> s;
		
		for (int i = 0; i < N; i++) {
			word[i] = s[i] - 'a';
		}

		if (K == 0)
			cout << "1\n";
		else if (checkisPalindrome() == 1) {
			cout << "1\n";
		}
		else if (checkisPalindrome() == 0) {
			cout << "2\n";
		}

	}




	return 0;
}
