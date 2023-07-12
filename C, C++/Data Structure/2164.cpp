#include <iostream>
#include <queue>

using namespace std;

queue <int> q;

int main() {

	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int n, check=0; 
	cin >> n;
	
	for (int i = 1; i <= n; i++)
		q.push(i);

	while (q.size() != 1) {
		int size = q.size();

		for (int i = 0; i < size; i++) {
			if (check == 0) {
				q.pop();
				check = 1;
			}
			else {
				int tmp = q.front();
				q.push(tmp);
				q.pop();
				check = 0;
			}
		}
	}
	cout << q.front() << endl;

	return 0;
}
