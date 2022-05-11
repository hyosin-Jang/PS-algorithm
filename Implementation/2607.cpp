#include <iostream>
#include<vector>
#include <cstring>

using namespace std;

void counting(int ar[26], string word) {
	int i;
	for (i = 0; i < word.length(); i++)
		ar[word[i] - 'A']++;
}
int solution(int n, vector<string>words) {
	int i, k;
	int diff, length;
	int freq_firstword[26] = { 0 }, freq_other[26] = { 0 }; // 각 알파벳 빈도 저장할 배열
	int answer = 0;

	length = words[0].length(); // 첫번째 단어 길이
	counting(freq_firstword, words[0]); // 첫번째 단어 알파벳 빈도 계산

	for (i = 1; i < n;i++) {
		diff = 0;
		memset(freq_other, 0, 26 * sizeof(int)); // 배열 초기화
		counting(freq_other, words[i]); // 나머지 단어들의 알파벳 빈도 계산

		for (k = 0; k < 26; k++) // 알파벳 개수 차이 계산
			diff += abs(freq_other[k] - freq_firstword[k]);

		if (diff == 0 || diff == 1 || (diff == 2 && words[i].length() == length)) answer++;
	}

	return answer;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);

	int n, i;
	int answer = 0;
	cin >> n;
	vector<string> words(n);
	for (int i = 0; i < n; i++)
		cin >> words[i];

	answer = solution(n, words);
	cout << answer << "\n";

	return 0;
}
