#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;
vector <string> v;
vector <string> v_result;

int main() {

	int n, m;
	string str;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> str;
		v.push_back(str);
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < m; i++) {
		cin >> str;
		if (binary_search(v.begin(), v.end(), str)) {
			v_result.push_back(str);
		}
	}
	sort(v_result.begin(), v_result.end());

	printf("%d\n", (int)v_result.size());
	for (int i = 0; i < v_result.size();i++)
		printf("%s\n", v_result[i].c_str());
		

	return 0;
}