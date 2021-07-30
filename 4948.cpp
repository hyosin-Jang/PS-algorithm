#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n, root;

	while (1) {
		cin >> n;
		if (n == 0) break;
		int cnt = 0;
		for (int i = n + 1; i <= 2 * n; i++) {
			
			root = sqrt(i);
			if (root == 1 && i != 1) {
				cnt++;
				continue;
			}
			if (i % 2) { // È¦¼öÀÏ °æ¿ì
				for (int j = 2; j <= root; j++) {
					if (i % j == 0) break;
					if (j == root)
						cnt++;
				}		
			}
		}
		cout << cnt << '\n';
	}

	
	return 0;
}