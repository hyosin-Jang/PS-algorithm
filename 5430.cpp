#include <iostream>
#include<deque>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T, n, i;
	string p, num;
	bool fr, err;
	cin >> T;
	while (T--) {
		deque <int> dq;
		fr = true;
		err = false;
		cin >> p >> n >> num;
		i = 1;
		while (num[i] != '\0') {
			int x = 0;
			while (num[i] >= '0' and num[i] <= '9') {
				x *= 10;
				// 숫자로 바꿔서 x에 저장
				x += int(num[i] - '0');
				i++;
			}
			if (x != 0)
				dq.push_back(x);
		i++;
	}
	i = 0;
	while (p[i] != '\0') {
		if (p[i] == 'R')
			fr != fr; // false
		else if (p[i] == 'D') {
			// 비어있다면 error 출력
			if (dq.empty()) {
				cout << "error" << endl;
				err = true;
				break;
			}
			if (fr)
				dq.pop_front();
		
		else
			dq.pop_back();
	}
	i++;
	}
	if (!err) 
		cout << "[";
	
	while (!dq.empty()) {
		if (fr) {
			auto c = dq.front();
			dq.pop_front();
			cout << c;
		}
	else {
		auto c = dq.back();
		dq.pop_back();
		cout << c;
	}
	if (!dq.empty())
		cout << ",";
	}
	if (!err)
		cout << "]" << endl;
	

	return 0;
}