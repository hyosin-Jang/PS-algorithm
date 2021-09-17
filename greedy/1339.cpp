#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector <string> word;
int alpha[26]; // 어떤 알파벳이 사용되었는지 확인
int result = 0;

void solution() {
	// CAB 이면, 
	// alpha의 B칸에 1 들어가있고
	// A칸에 10들어가있고
	// C칸에 100들어가있음
	for (int i = 0; i < word.size(); i++) {
		int pow = 1;
		for (int j = word[i].size() - 1; j >= 0; j--) {
			int val = word[i][j] - 'A';
			alpha[val] += pow;
			pow *= 10;

		}
	}

	sort(alpha, alpha + 26);
	int num = 9;
	// 9부터 시작해서 하나씩 감소
	for (int i = 25; i >= 0; i--) {
		if (alpha[i] == 0) break;
		result += (alpha[i] * num);
		num--;
	}
}

int main() {

	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int n;
	string s;
	cin >> n;

	// 1. Input
	for (int i = 0; i < n; i++) {
		cin >> s;
		word.push_back(s);
	}
	solution();
	
	cout << result;

	return 0;
}
