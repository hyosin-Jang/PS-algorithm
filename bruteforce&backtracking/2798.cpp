#include <iostream>
using namespace std;

int N, M;
int arr[101];
int answer = 0;


// N장 중에서 M과 최대한 가까운 3장 고르는 문제 
void card() {
	// i=0, j=1, k=2

	for (int i = 0; i < N - 2 ; i++) 
		for (int j = i + 1; j < N - 1; j++) 
			for (int k = j + 1; k < N; k++) 
				if (arr[i] + arr[j] + arr[k] <= M) 
					answer = max(answer, arr[i] + arr[j] + arr[k]);
}

int main() {

	cin >> N >> M; // 5 21

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	card();

	cout << answer << "\n";

	return 0;
}
