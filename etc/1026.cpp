#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector <int> A,B;

int main() {
	int N, n, S=0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n;
		A.push_back(n);
	}
	sort(A.begin(), A.end());

	for (int i = 0; i < N; i++) {
		cin >> n;
		B.push_back(n);
	}
	sort(B.rbegin(), B.rend());

	for (int i = 0; i < N; i++)
		S += A[i] * B[i];

	cout << S << endl;
	
	return 0;
}