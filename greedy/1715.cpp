#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, num;
	cin >> N;

	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < N; i++) {
		cin >> num;
		pq.push(num);
	}
	int subtotal = 0, total=0;

	while (pq.size() > 1) {
		// 2개 pop하기
		int num1, num2;
		num1 = pq.top();
		pq.pop();
		num2 = pq.top();
		pq.pop();

		subtotal = num1 + num2;
		
		pq.push(subtotal);
		
		total += subtotal;
	}

	cout << total << endl;


	return 0;
}
