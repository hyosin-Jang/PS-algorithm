#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int main(void) {
	int n;
	cin >> n;

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		if (!num && pq.empty())
			cout << 0 << "\n";
		else if (!num) {
			cout << pq.top() << "\n";
			pq.pop();
		}
		else
			pq.push(num);
	
	
	}

	return 0;
}