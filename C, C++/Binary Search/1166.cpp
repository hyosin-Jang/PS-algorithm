#include <iostream>
#include <cstdio>
#include <map>
typedef long long ll;
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, L, W, H;

	double l = 0, r = 1000000000, mid;

	cin >> N >> L >> W >> H;

	for (int i = 0; i < 10000; i++) {
		mid = (l + r) / 2; // mid: 박스 한 변의 길이
		if ( ((ll)(L / mid)) * ((ll)(W / mid)) * ((ll)(H / mid)) < N ) r = mid; // 박스 길이 줄임
		else l = mid; // 개수가 N보다 작은 경우, 박스 길이 늘림
	}

	printf("%.10lf", l); 

	return 0;
}
