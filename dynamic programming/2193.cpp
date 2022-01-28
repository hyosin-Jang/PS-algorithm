#include <iostream>

using namespace std;
int N;

long long arr[91];
// arr[a] = b; a자리 이친수의 개수는 b개
// 풀이가 맞는데 틀렸다고 나오면 자료형을 확인해보자!
int main() {

	cin >> N;
	arr[1] = 1;
	arr[2] = 1;

	for (int i = 3; i <=N; i++)
		arr[i] = arr[i - 1] + arr[i - 2];
	
	cout << arr[N] << endl;
	

	return 0;
}
