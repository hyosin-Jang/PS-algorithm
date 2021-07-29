#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

vector<int> v;
vector<char> ans;

int main() {
	int n, cnt=0, amx;
	int str[100001];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> str[i];

	for (int i = 1; i <= n; i++) {
		v.push_back(i);
		ans.push_back('+');

		while (!v.empty() && v.back() == str[cnt]) {
			v.pop_back();
			ans.push_back('-');
			cnt++;
		}
	}
	if (!v.empty()) 
		cout << "NO";
	else 
		for (int i = 0; i < ans.size(); i++) 
			cout << ans[i] << '\n';


	return 0;
}