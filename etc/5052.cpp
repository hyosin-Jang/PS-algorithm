#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
using namespace std;

vector <string> v;

int main() {
	int T, n, flag=1;
	string num;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> num;
			v.push_back(num);
		}
		sort(v.begin(), v.end());

		for (int i = 0; i < n - 1; i++) {
			int current = v[i].length();
			int next = v[i + 1].length();

			if (current < next) {
				// 1234              12
				if (v[i + 1].find(v[i]) == 0) {
					flag = 0;
					printf("%d %d\n", v[i+1], v[i]);
					break;
				}
			}
		}

		if (flag)
			printf("YES\n");
		else
			printf("NO\n");

	}
	return 0;
}