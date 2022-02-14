#include <iostream>
#include <deque>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	cin.sync_with_stdio(false);

	int n, card;

	cin >> n;

	deque <int> dq, A, B;

	// 덱에 27장 넣어놓기
	for (int i = 0; i < 27; i++) {
		dq.push_back(i); // 0번이 조커
	}


	for (int i = 0; i < n ; i++) {
		int sum = 0;

		// 초기화
		// 13장 => A
		for (int a = 0; a < 13; a++) {
			int tmp = dq.front();
			dq.pop_front();
			A.push_back(tmp);
		}
		// 14장 => B
		for (int b = 0; b < 14; b++) {
			int tmp = dq.front();
			dq.pop_front();
			B.push_back(tmp);
		}

		int j = 1;

		// Aij 입력받기
		while (sum!=27) {
			cin >> card; // 13

			// 홀수라면
			if (j % 2 == 1) {
				// B에서 위에서부터 card장 빼기
				for (int k = 0; k < card; k++) {
					int tmp = B.front();
					B.pop_front();
					dq.push_back(tmp);

				}
			}
			
			// 짝수라면
			else {
				for (int k = 0; k < card; k++) {
					int tmp = A.front();
					A.pop_front();
					dq.push_back(tmp);
		
				}
			}

			sum += card;
			j++;
		}

		// 합이 27이 되면 나옴
	
	}

	for (int i = 0; i < 27; i++)
	{
		if (dq[i] == 0)
			cout << i + 1 << endl;
	}


	return 0;
}
