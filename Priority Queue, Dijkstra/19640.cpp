#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
using namespace std;

struct employee {
	int d, h, line_no, k;
};

struct compare {
	bool operator()(employee e1, employee e2) {
		if (e1.d == e2.d) { // 근무일수가 같다면
			if (e1.h == e2.h) { // 급한 정도가 같다면
				return e1.line_no > e2.line_no;
			}
			return e1.h < e2.h;
		}
		return e1.d < e2.d;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);

	priority_queue<employee, vector<employee>, compare> pq;
	vector<queue<employee>> line; // 줄

	int n, m, k, day, hurry;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> day >> hurry;
		// i%m번줄
		pq.push({ day, hurry, i % m, i });
	}
	for (int i = 1; i <= n; i++) {
		
	
	}
	return 0;
}
