#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N, K, answer;
int alphabet[27] = {0}; // 나온 알파벳 기록하는 배열
string s[51];

// cnt==K-5가 될 때 K개의 글자 중 읽을 수 있는 단어 개수 계산
int CanReadNum() {
	bool Read;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		Read = true;
		string str = s[i];
		for (int j = 0; j < str.length(); j++) {
			if (alphabet[str[j] - 'a'] == 0) { // 하나라도 0이면 읽을 수 없음
				Read = false;
				break;
			}
		}

		if (Read == true)
			cnt++;

	}
	return cnt;

}

// 조합
void dfs(int num, int cnt) {
	if (cnt == K-5) { // 최대 K-5개
		answer = max(answer, CanReadNum());
		return;	
	}
	// for문 한번씩 돌때마다 한줄씩 출력
	for (int i = num; i < 26; i++) {
		if (alphabet[i] == 1) continue; // 이미 포함된거니까 넘어가기
		alphabet[i] = 1;
		dfs(i, cnt + 1); // cnt +1 까지 더 깊게 들어가기
		alphabet[i] = 0; // 백트래킹
	}
}


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;

	// a, n, t, c, i 는 1로 만들기
	alphabet[0] = 1;
	alphabet['n' - 'a'] = 1;
	alphabet['t' - 'a'] = 1;
	alphabet['c' - 'a'] = 1;
	alphabet['i' - 'a'] = 1;

	for (int i = 0; i < N; i++) {
		cin >> s[i]; // antarctica
	}

	if (K < 5) {
		cout << 0 << endl;
		return 0;
	}


	// 1인 것들로만 K-5개 조합 구하기
	dfs(0, 0);

	cout << answer << "\n";
	

	return 0;
}
