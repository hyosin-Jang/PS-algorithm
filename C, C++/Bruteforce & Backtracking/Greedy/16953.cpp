#include <iostream>
using namespace std;

int mini = 10000; //임의의 큰 수
long long a, b, cnt;

void dfs(long long a, int cnt) {
	if (a > b) return;
	if (a == b) {
		mini = min(mini, cnt);
	}
	dfs(a * 2, cnt + 1);
	dfs(a * 10 + 1, cnt + 1);

}
int main() {
	cin >> a >> b;

	dfs(a, 1);
	if (mini == 10000) cout << -1;
	else cout << mini;


	return 0;
}
