#include <iostream>
#include <cmath>
using namespace std;

// while문 안에 while문 중첩

int N, K;

int main() {

	cin >> N >> K;
	if (N <= K) {
		cout << 0 << endl;
		return 0;
	}
	
	int result;
	for (result = 0; ;result++) {
		int cnt = 0;
		int tempN = N;
		while (tempN) {
			if (tempN % 2)
				cnt++;
			tempN /= 2;
		
		}
		if (cnt <= K)
			break;
		N++;
	
	
	}
	
	cout << result << endl;


	return 0;
}
