#include <iostream>
#include <stack>

using namespace std;

stack<int> s;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string input;
	int n,cnt=0;
	cin >> n;
	for (int i = 0; i < n;i++) {
		cin >> input;
		for (int j = 0; j < input.length(); j++) {
			if (!s.empty()) {
				if (s.top() == input[j])
					s.pop();
				else
					s.push(input[j]);
			}
			else { s.push(input[j]); }
		
		}
		if (s.empty())
			cnt++;

		// 스택 초기화
		while (!s.empty()) s.pop();
	}

	cout << cnt << endl;

	return 0;
}
