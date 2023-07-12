#include <iostream>

using namespace std;
int arr[1002];
int answer[1002];
int n, k, cnt = 0, ptr = 1; 

void findPermutation() {
	while (cnt != n) {
		for (int i = 0; i < k - 1; i++) {
			while (arr[ptr] == 0) {
				ptr++;
				if (ptr == n + 1) ptr = 1;
			}
			ptr++;
			if (ptr == n + 1) ptr = 1;
			while (arr[ptr] == 0) {
				ptr++;
				if (ptr == n + 1) ptr = 1;
			}
		}
		arr[ptr] = 0; 
		answer[cnt++] = ptr;

	}
}

int main() {

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		arr[i] = 1;
	if (k == 1)
		for (int i = 0; i < n; i++)
			answer[i] = i + 1;
	else
		findPermutation();
	cout << "<";
	for (int i = 0; i < n; i++) {
		if (i == n - 1)
			cout << answer[i] << ">";
		else
			cout << answer[i] << ", ";
	}

	return 0;
}
