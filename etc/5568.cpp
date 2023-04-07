#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

int n, k;
unordered_set <string> us;
vector<int> v;
vector<int> visited;

void fun(string sum, int counter) {

	if (counter != k) {

		for (int i = 0; i < n; i++) {

			if (visited[i] == 0) {

				// 방문 체크
				visited[i] = 1;

				// 재귀 호출
				fun(sum + to_string(v[i]), counter + 1);
				visited[i] = 0;
			}
		}

	}
	else
		us.insert(sum);

}

int main() {
	cin >> n >> k;
	v.assign(n, 0);
	visited.assign(n, 0);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	fun("", 0);
	cout << us.size();
	return 0;

}
