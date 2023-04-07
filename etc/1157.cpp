#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string s;
	cin >> s;

	// 알파벳배열
	int num[27] = { 0, };

	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 97) {
			s[i] = s[i] - 32;
		}
		num[s[i] - 65]++;
	}

	int max = 0, index, cnt = 0;

	for (int i = 0; i < 26; i ++ ) {
		if (max < num[i]) {
			max = num[i];
			index = i;
		}
	
	}
	// 최대 개수가 여러개인 경우
	for (int i = 0; i < 26; i++)
		if (i != index && max == num[i])
			cnt++;
	
	if (cnt != 0)
		cout << "?\n";
	else
		cout << (char)(index + 65) << "\n";



	return 0;
}