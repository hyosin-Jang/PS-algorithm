#include <iostream>
#include <stack>
using namespace std;

stack <int> s;
int k, tmp, sum=0;
int main() {
	cin >> k;

	for (int i = 0; i < k;i++) {
		cin >> tmp;
		if (tmp == 0) {
			sum -= s.top();
			s.pop();
		}
		else {
			s.push(tmp);
			sum += tmp;
		}
	}

	cout << sum << endl;

	return 0;
}
