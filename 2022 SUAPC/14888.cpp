#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 11;

// dfs로 조합 구하기
int arr[MAX] = {0, };
int sign[MAX];
int N;
int max_num = -1000000001;
int min_num = 1000000001;

void dfs(int num, int cnt) { 
	if (cnt == N) {
		max_num = max(max_num, num);
		min_num = min(min_num, num);
		return;	
	}

	for (int i = 0; i < 4; i++) {
		if (sign[i] > 0) {
			sign[i]--; // 연산자 하나 사용했으므로 하나 줄여줌
			if (i == 0)
				dfs(num + arr[cnt], cnt + 1);
			else if (i == 1)
				dfs(num - arr[cnt], cnt + 1);
			else if (i == 2)
				dfs(num * arr[cnt], cnt + 1);
			else
				dfs(num / arr[cnt], cnt + 1);
			sign[i]++; // 다른 연산자를 사용할 것이므로 아까 줄였던 연산자 개수 늘려줌
		}


	}
	return;
}

int main() {

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	for (int i = 0; i < 4; i++)
		cin >> sign[i];
	dfs(arr[0], 1);

	cout << max_num << "\n";
	cout << min_num << "\n";

	return 0;
}
