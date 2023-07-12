#include <iostream>
#include <string>
using namespace std;

string s, ring;
int n, tmpCnt=0, cnt=0;
int main() {
	cin >> s >> n;

	// PQR
	// PQPQR
	// ring.find의 반환 값이 0이 나오는 경우 고려하기

	for (int i = 0; i < n;i++) {
		cin >> ring;
		int idx = ring.find(s[0]); // 8
		if (idx == string::npos)
			continue;
		else {
			int tmp = 0, tmpCnt=0;

			for (int k = 0; k < s.length(); k++) {
				if (idx == ring.length()) idx = 0;
				if (s[tmp++] == ring[idx++])
					tmpCnt++; // 2

			}
			if (tmpCnt == s.length())
				cnt++;

		}

	}

	cout << cnt << endl;

	return 0;
}
