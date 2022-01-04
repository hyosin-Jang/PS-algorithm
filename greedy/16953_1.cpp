#include <iostream>
#include <queue>
typedef long long int lli;
using namespace std;

int a, b, cnt=1, ans=-1;

// cnt 값을 각 숫자가 기억할 수 있도록 
// <현재숫자, cnt> pair로 큐에 저장해줬다. 

void BFS() {
	lli x, cnt, c1, c2;
	queue <pair<lli, lli>> q; // <현재 숫자, cnt>
	q.push({a ,1});
	
	while (!q.empty()) {
		x = q.front().first;
		cnt = q.front().second;
		q.pop();

		if (x == b) {
			ans = cnt;
			break;
		}
		c1 = x * 2;
		c2 = x * 10 + 1;

		if (c1 <= b)
			q.push({c1, cnt + 1});
		
		if (c2 <= b)
			q.push({c2, cnt +1});
	
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> a >> b;
	
	BFS();

	cout << ans << endl;

	return 0;
}
