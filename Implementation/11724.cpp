#include <iostream>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	set<int> set;
	int n, x;
	string s;
	cin >> n;
	while (n--) {
		cin >> s;
		if (s == "add") {
			cin >> x;
			set.insert(x);
			continue;
		}
		else if (s == "check") {
			cin >> x;
			if (set.find(x) != set.end())
				cout << "1\n";
			else cout << "0\n";
			continue;
		}
		else if (s == "remove") {
			cin >> x;
			if (set.find(x) != set.end())
				set.erase(x);
			continue;
		}
		else if (s == "toggle") {
			cin >> x;
			if (set.find(x) != set.end())
				set.erase(x);
			else set.insert(x);
			continue;
		}
		else if (s == "all") {
			set.clear();
			for (int i = 1; i <= 20; i++)
				set.insert(i);
			continue;
		}
		else set.clear();
	}

	return 0;
}
