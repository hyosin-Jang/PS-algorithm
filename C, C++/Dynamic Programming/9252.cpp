#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int MAX = 1001;
int dp[MAX][MAX];
string LCS[MAX][MAX];

int main() {
	string s1, s2;

	cin >> s1 >> s2;

	// s1은 세로, s2는 가로
	for (int i = 1; i <= s1.size(); i++) {
		for (int j = 1; j <= s2.size(); j++) {
			if (s1[i - 1] == s2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1; // 왼쪽위 대각선 +1
				LCS[i][j] = LCS[i - 1][j - 1] + s1[i - 1];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				LCS[i][j] = (LCS[i - 1][j].length() > LCS[i][j - 1].length())
					? LCS[i - 1][j] : LCS[i][j - 1];
			}
		}
	}
	if (dp[s1.length()][s2.length()] == 0)
		cout << 0;
	else {
		cout << dp[s1.length()][s2.length()] << "\n";
		cout << LCS[s1.length()][s2.length()] << endl;
	}

	return 0;
}

