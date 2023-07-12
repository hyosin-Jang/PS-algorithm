#include <iostream>
#include <algorithm>
using namespace std;

// 오래 걸리는 사람일수록 뒤에 서서
// 대기 시간을 최소로 만들기
int arr[1001];
int main() {
	int N, sum=0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	// arr 오름차순 정렬하기
	// 배열 시작점 주소, 마지막 주소 +1
	sort(arr, arr + N);

	for (int i = 1; i < N; i++)
		arr[i] += arr[i - 1];
	
	for (int i = 0; i < N; i++)
		sum += arr[i];

	cout << sum << endl;



	return 0;
}
