#include <iostream>
#include <queue>
using namespace std;

queue <int> q;

int main() {

	int N;
	cin >> N;
	while (N--) {
		string tmp;
		cin >> tmp;

		if (tmp == "push") {
			int t;
			cin >> t;
			q.push(t);
		}

		else if (tmp == "pop") {
			if (q.empty()) cout << "-1\n";
			else {
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (tmp == "size") cout << q.size() << "\n";
		else if (tmp == "empty") {
			if (q.empty())
				cout << "1\n";
			else cout << "0\n";
		}
		else if (tmp == "front") {
			if (q.empty())
				cout << "-1\n";
			else
				cout << q.front() << "\n";
		}
		else {
			if (q.empty())
				cout << "-1\n";
			else
				cout << q.back() << "\n";
		}

	}

	return 0;
}
