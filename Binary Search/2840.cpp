#include <iostream>
#include <vector>
#include <map>

using namespace std;

// 원형 큐 - 배열로 구현
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, k, num;
	char letter;
	cin >> n >> k;
	vector<char> wheel(n, 0); // n개가 0으로 초기화됨
	int cur = 0; // 현재 0번 위치에서 시작
	while (k--) {
		cin >> num >> letter; 
		while (num--) { // num 만큼 현재 인덱스 이동
			cur++;
			if (cur == n) cur %= n;
		}
		if (wheel[cur] && wheel[cur] != letter) { // 값이 들어있는데 letter랑 다르다면
			cout << "!\n"; return 0;
		}
		if (wheel[cur] == letter) continue; // 값이 들어있지 않거나, letter랑 같다면
		wheel[cur] = letter; // letter 넣기
	}
	map<char, int> m;
	for (int i = 0; i < n;i++) {
		if (wheel[i]) m[wheel[i]]++;
		if (m[wheel[i]] > 1) {
			cout << "!"; return 0;
		}
	}

	for (int i = 0; i < n; i++) {
		if (!wheel[cur]) cout << "?";
		else cout << wheel[cur];
		cur--;
		if (cur < 0)
			cur +=n; // 2
	}

	return 0;
}
