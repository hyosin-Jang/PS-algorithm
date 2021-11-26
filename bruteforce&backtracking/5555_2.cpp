#include <iostream>
#include <string>
#include<vector>
using namespace std;

string s;
int n, cnt=0;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> s >> n;
	vector<string> next(n);

	for (int i = 0; i < n;i++) {
		cin >> next[i];
		// 시작과 끝 연결
		next[i] = next[i] + next[i];
		if (next[i].find(s) != string::npos) cnt++;
		
	}

	cout << cnt << endl;

	return 0;
}
