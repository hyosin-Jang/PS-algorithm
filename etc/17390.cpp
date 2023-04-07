#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int N, Q, L, R;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> N >> Q;
	vector<ll> v(N+1);
	v[0] = 0;
	for (int i = 1; i <= N; i++)
		cin >> v[i];
	
	sort(v.begin(), v.end());

	for (int i = 1; i <= N; i++)
		v[i] += v[i - 1];

	while(Q--) {
		cin >> L >> R;
		cout << v[R] - v[L - 1] << "\n";
	}


	return 0;
}
