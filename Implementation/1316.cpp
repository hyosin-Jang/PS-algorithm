#include <iostream>
using namespace std;

int arr[27];
int N;
int main() {
	cin >> N;
	string s;

	int cnt = N;
	for (int i = 0; i < N; i++) {
		cin >> s;

		for (int j = 0; j < s.length(); j++) {
			if (arr[s[j] - 'a'] == 0) {
				arr[s[j] - 'a']++;
				continue;
			}
			else if (s[j - 1] == s[j]) {
				arr[s[j] - 'a']++;
				continue;
			}
			else {
				cnt--;
				break;
			}
		}
		
		for (int k = 0 ; k < 27 ; k++)
			arr[k] = 0;
	}

	cout << cnt << endl;


	return 0;
}
