#include <iostream>
using namespace std;

int N, bag_count;

void Solve() {
	int quote, remainder, i;
	
	// 5로 나눴을 때 최대 몫에서 하나씩 빼면서 계산
	quote = N / 5;
	while (quote >= 0) { 
		remainder = N - quote * 5; 
		if (remainder % 3 == 0) { 
			bag_count += remainder / 3;
			bag_count += quote;
			cout << bag_count << endl;
			break;
		}
		quote--; // 0
	
	}
	if(quote < 0)
		cout << -1 << endl;

}
int main() {
	cin >> N;
	
	if (N == 3 || N==5)
		cout << 1;
	else if (N == 4)
		cout << -1;
	else if (N % 5 == 0)
		cout << N / 5;
	else
		Solve(); // N이 5의 배수가 아니고, 6 이상인 경우



	return 0;
}
