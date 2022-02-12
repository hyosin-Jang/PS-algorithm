#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int T, N;
	string school;
	int drink;

	string max_school;
	int max_cnt=0;

	cin >> T;

	while (T--) {

		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> school >> drink;

			if (max_cnt < drink) {
				max_cnt = drink;
				max_school = school;

			}
		}

		cout << max_school << "\n";

	}


	return 0;
}
