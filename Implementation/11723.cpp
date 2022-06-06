#include <iostream>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t, num=0;
	string op;
	cin >> t;
	set<int> s;
	set<int> allset = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };

	while (t--) {
		cin >> op;
		if (op == "add") {
			cin >> num;
			s.insert(num);
			continue;
		}
		if(op == "remove") {
			cin >> num;
			s.erase(num);

			continue;
		}
		if (op == "check") {
			cin >> num;
			if (s.find(num) == s.end()) {
				cout << "0\n";
			}
			else cout << "1\n";
			continue;
		}
		if (op == "toggle") {
			cin >> num;
			if (s.find(num) != s.end()) {
				s.erase(num);
			}
			else s.insert(num);
			continue;
		}
		if (op == "all") {
			s = allset; // 미리 1-20까지 넣어준 애를 s에 넣어주기
			continue;
		}
		if (op == "empty") {
			s.clear(); // O(logN)
		}
	}
	return 0;
}
