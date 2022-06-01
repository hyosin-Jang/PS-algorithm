#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int alphabet[26] = { 0 }; // 알파벳 출현 여부

int n, k, ans=0;
vector<string> word;

int canReadNum() {
	// N개의 단어 중에서 현재 k개의 알파벳의 조합으로 읽을 수 있는 단어 개수 리턴
	int cnt = 0;

	for (int i = 0; i < n; i++) { // i: 현재 단어
		// i번째 단어 word[i];
		int flag = 0;
		for (int j = 0; j < word[i].size(); j++) {
			if (alphabet[word[i][j]-'a'] == 0) {
				flag = 1;
				break; // 현재 단어 나가기
			}
		}
		if (flag == 1) continue; // 다음 단어로 넘어가기
		cnt++; // 여기까지 도달했으면 cnt ++ 
	
	}
	return cnt;
}

void dfs(int num, int cnt) {
	if (cnt == k - 5) { // 종료 조건, 가능한 영단어 개수 구하기
		ans = max(ans, canReadNum());
		return;
	}
	for (int i = num ; i < 26; i++) {
		if (alphabet[i] == 1) continue; // 이미 포함시킨 것이므로 다음으로 넘어가기
		
		// alphabet[i] == 0인 경우, 
		alphabet[i] = 1; // 방문 표시
		dfs(i, cnt + 1);
		alphabet[i] = 0; // 방문 해제
	}
}

int main() {
	cin >> n >> k;
	alphabet[0] = 1;
	alphabet['n' - 'a'] = 1;
	alphabet['t' - 'a'] = 1;
	alphabet['i' - 'a'] = 1;
	alphabet['c' - 'a'] = 1;

	string w;
	for (int i = 0; i < n; i++) {
		cin >> w;
		word.push_back(w);
	}
	if (k < 5) {
		cout << "0\n";
		return 0;
	}
	dfs(0, 0);

	cout << ans << '\n';

	return 0;
}
