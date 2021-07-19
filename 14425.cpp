#include <iostream>
#include <vector>
#include<algorithm>
#include <map>
#include <set>
#include <string>

# define SIZE 30

using namespace std;

set <string> Set;

int main() {
	int n, m;
	string word;

	cin >> n >> m;

	for (int i = 0; i < n;i++) {
		cin >> word;
		Set.insert(word);
	}

	int cnt = 0;
	for (int i = 0; i < m; i++) {
		cin >> word;
		if (Set.find(word) != Set.end())
			cnt++;
	}
	cout << cnt;


	return 0;
}