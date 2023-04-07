#include <iostream>

using namespace std;

int main() {
	string pattern, tmp;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		// 처음에는 pattern에 입력 받고
		if (i == 0) cin >> pattern;
		else {
			cin >> tmp;
			for (int j = 0; j < pattern.length(); j++)
				if (tmp[j] != pattern[j])
					pattern[j] = '?';
		}
	}
	cout << pattern << endl;

	return 0;
}
