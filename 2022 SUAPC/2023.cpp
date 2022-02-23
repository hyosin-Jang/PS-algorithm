#include <iostream>
#include <cmath>
using namespace std;
const int MAX = 9;

typedef long long ll;
int arr[MAX] = {0, };
int N, M;

bool isPN(ll x) {
	if (x < 2)
		return false;

	for (ll i = 2; i * i <= x; i++)
		if (x % i == 0) return false;
	return true;
}

void dfs(int cur, int cnt) {  // (현재 숫자, 자릿수)
	if (cnt == 0) { // 자릿수가 0이 되면 현재 숫자 출력
		cout << cur << endl;
		return;	
	}
	for (int i = 1; i < 10; i+=2) { // 두번째 자리부터는 홀수만 더해줌
		    arr[cnt] = i;

			int tmp = cur * 10 + i; // cnt+1자리 숫자만들기

			if(isPN(tmp))
				dfs(tmp, cnt-1); 
	
	}
}

int main() {

	cin >> N;

	// 맨 첫자리는 prime에서 시작
	int prime[4] = { 2, 3, 5, 7 };
	for (int i = 0; i < 4; i++)
		dfs(prime[i], N - 1);


	return 0;
}
