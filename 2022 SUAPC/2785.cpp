#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int N;
vector <int>v;

int main() {

	int temp, ans=0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> temp;
		v.push_back(temp);
	}

	// 오름차순 정렬
	sort(v.begin(), v.end());

	int i = 0;
	// 작은거 고리풀어서 연결하기

	int A = N-1;

	// A = 남은 체인 개수
	if (A > v[i]) {

		int min = v[i++];

		// 첫번째 꺼로는 min개만큼 커버가능
		ans += min;

		// 나머지는 
		A -= min;

		// 한번만 끊을 수 있는 상황에서는,,
		if (A <= v[i])
			cout << ans << "\n";

		// 여러개 끊을 수 있는 경우
		else {
			while (A > v[i]) {
				min = v[i++];
				ans += min;
				A = A - min - 1;
			}
			if (A>0)
				ans += (A - 1);
		

			cout << ans << "\n";
		}
	}
	// 그냥 연결
	else {
		cout << N - 1 << "\n";
	}


	return 0;
}
