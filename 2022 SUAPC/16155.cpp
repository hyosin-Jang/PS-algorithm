#include <iostream>

using namespace std;
typedef long long ll;
ll X[60];
ll Y[60];
int n;

// X값 들어오면 X가 속한 구간에서 대응하는 Y값 리턴하는 함수 
pair<ll, ll> findY(ll x) {

	for (int i = 0; i <= n + 1; i++) {

		 if (x >= X[i] && x < X[i + 1]) {
			
			// 분자
			ll num = (x - X[i]) * Y[i + 1] + (X[i + 1] - x) * Y[i];

			// 분모
			ll denom = X[i + 1] - X[i];
			return make_pair(num, denom);
			
		}

	}

}

int gcd(int a, int b) {

	int c;
	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}


int main() {
	cin.tie(NULL); cout.tie(NULL);
	cin.sync_with_stdio(false);

	ll s, e;

	cin >> n;

	// X[0], Y[0]은 시작지점
	// 이후 n개의 체크포인트 입력받음
	for (int i = 0; i < n + 1; i++)
		cin >> X[i] >> Y[i];

	// 마지막 점을 위해서 계산하기 편하게 넣어줌
	X[n + 1] = 6000;


	cin >> s >> e;

	ll a_num = findY(s).first;  // 시작점 분자
	ll a_denom = findY(s).second;  // 끝점 분모

	ll b_num = findY(e).first;  // 두 번째 점 분자
	ll b_denom = findY(e).second;  // 두 번째 점 분모

	ll ans_x = a_denom * b_denom * (e - s);
	ll ans_y = abs(a_num * b_denom - b_num * a_denom);

	ll gn = gcd(ans_x, ans_y);
	ans_x = ans_x / gn; ans_y = ans_y / gn;

	if (ans_y == 0)
		cout << "0\n";
	else if (ans_x == 1) // 분모가 1인 경우
		cout << ans_y << "\n";
	else
		cout << ans_y << "/" << ans_x << "\n";

	return 0;
}
