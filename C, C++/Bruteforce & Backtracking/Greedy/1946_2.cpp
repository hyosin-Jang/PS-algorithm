#include <iostream>
#include <algorithm>

const int MAX = 100000;
using namespace std;
pair<int, int> employee[MAX];

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0); //실행속도 향상

	int T, N, cutline, first_case, second_case;

	cin >> T;

	while (T--) {
		int acceptance = 1;

		cin >> N;

		for (int i = 0; i < N; i++)
			cin >> employee[i].first >> employee[i].second;

		sort(employee, employee + N);

		cutline = employee[0].second;

		// 아랫 순위는 적어도 윗 순위보다 두번째 값이 작아야 함
		for (int i = 1; i < N; i++) {
			if (employee[i].second < cutline) {
				acceptance++;
				cutline = employee[i].second;
			}
		}
		cout << acceptance << "\n";
	}

	return 0;
}
