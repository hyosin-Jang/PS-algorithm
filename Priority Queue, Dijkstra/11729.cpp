#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int> pq;
	int n, x;
	cin >> n;
	while (n--) {
		cin >> x;
		if (x == 0 && pq.empty()) {
			cout << "0\n";
			
		}
		else if (x == 0 & !pq.empty()) {
			cout << pq.top() << "\n";
			pq.pop();
		}
		else 
			pq.push(x);
	}

	return 0;
}
