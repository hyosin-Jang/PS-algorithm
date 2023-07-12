#include <iostream>
#include <stack>
using namespace std;


int main() {
	string s;
	cin >> s;
	stack <char> left; // 커서 기준 왼쪽 스택
	stack <char> right; // 커서 기준 오른쪽 스택
	for (int i = 0; i < s.size(); i++)
		left.push(s[i]);

	int N;
	cin >> N;

	while (N--) {
		char tmp;
		cin >> tmp;
		// 1. P $
		if (tmp == 'P') {
			char c;
			cin >> c;
			left.push(c); // 왼쪽 스택에 push
		}
		// 2. L일 경우, 왼쪽 스택 pop, 오른쪽 스택에 push
		// pop할 때는 항상 비어있는지 체크하기
		else if (tmp == 'L') {
			if (left.empty()) continue;
			else {
				right.push(left.top());
				left.pop();
			}	
		}
		// 3. B일 경우, 왼쪽 스택 pop
		else if (tmp == 'B') {
			if (left.empty()) continue;
			else 
				left.pop();
		}
		// 4. D일 경우, 오른쪽 스택 pop, 왼쪽 스택에 push
		else if (tmp == 'D') {
			if (right.empty())continue;
			else {
				left.push(right.top());
				right.pop();
			}
		}
	}
 
	// 5. 출력, 왼쪽 스택 원소 전부 오른쪽 스택으로 이동
	while (!left.empty()) {
		right.push(left.top());
		left.pop();
	}

	while (!right.empty()) {
		cout << right.top();
		right.pop();	
	}
	return 0;
}
