#include <iostream>
#include <vector>

using namespace std;


int main() {
	int N, tmp, max= -1000001, min= 1000001;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		if (tmp > max)
			max = tmp;
		if (tmp < min)
			min = tmp;
	}
	cout << min << " " << max << endl;


	return 0;
}
