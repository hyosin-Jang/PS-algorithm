#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, t, answer=10e7;

	cin >> n >> t;
	vector <int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];

		if (t / v[i] > 0) {
			int num = t;
			int result = 0;

			for (int j = i; j >= 0; j--) {
				if (num / v[j] == 0) continue;
				result += num / v[j];
				num%= v[j];

				if (num == 0) break;
			
			}
			if (!num)
				answer = min(answer, result);
		
		}
	
	
	}
	cout << answer << endl;



	return 0;
}