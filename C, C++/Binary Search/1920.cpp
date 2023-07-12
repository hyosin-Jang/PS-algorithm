#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int arr[100001];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, M;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);
	cin >> M;
	for (int i = 0; i < M; i++) {
		int tmp, flag=0;
		int l = 0, r = N-1, mid;
		cin >> tmp;
		while (l <= r) {
			mid = (l + r) / 2; // 2
			if (arr[mid] == tmp) {
				cout << "1\n";
				flag = 1;
				break;
			}
			else if (arr[mid] > tmp) r = mid - 1;			
			else l = mid + 1;
		}
		if (flag == 1) continue;
		else cout << "0\n";
	}


	return 0;
}
