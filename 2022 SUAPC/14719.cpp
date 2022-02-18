#include <iostream>
#include <stack>
using namespace std;

const int MAX = 501;
int H, W;
int height[MAX];
stack <int> s;
int result=0;

void Solve() {
	// 가상의 arr이 있다고 생각하자
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			// 뚫린 경우
			if (i <= H - height[j] - 1)
				continue;

			// 막힌 경우 스택에 추가하기

			// 스택에 들어있는게 있다면
			if (!s.empty()) {
				int tmp = s.top();
				result += (j - tmp - 1);
				s.push(j);
				// cout << "넣을 때 ) i: " << i << " j: " << j << "\n";
			}
			else { // 스택이 비어있다면
				s.push(j);
			}

		}
	// 한 줄이 끝나면 스택에 있는거 다 빼기
		while (!s.empty())
			s.pop();
	
	
	}

	cout << result << endl;

}

int main() {
	cin >> H >> W;

	for (int i = 0; i < W; i++)
		cin >> height[i];
	
	Solve();

	return 0;
}
