#include <iostream>
using namespace std;

string str;

int solution() {

	int answer=0;

	for (int i = 0; i < str.length(); i++) {

		if (str[i] == '0') answer += 11;
		if (str[i] == '1') answer += 2;
		if (str[i] != '0' && str[i] != '1' && str[i] != 'q' && str[i] != 'z')
			answer += (str[i] - 'a' + 3) / 3 + 2;

		// q가 빠져서 s, v, y는 하나씩 앞당겨짐
		if (str[i] == 's' || str[i] == 'v' || str[i] == 'y') answer--;
	}

	return answer;
}

int main() {

	cin >> str;

	cout << solution() << endl;

	return 0;
}
