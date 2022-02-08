#include <iostream>
using namespace std;

const int MAX = 65;
int n;
int arr[MAX][MAX];


// 가로 길이
void QuadTree(int start, int n) {
	cout << "(";

	int c1, c2, c3, c4;

	// 1. 왼쪽 위 체크
	for (int i = start; i < n / 2; i++) {
		for (int j = start; j < n / 2 -1; j++) {
			if (arr[i][j] != arr[i][j + 1]) {
				QuadTree((i + 1) / 2, n / 2);
			
			
			
			}
		
		}
	}
	// -- 모두 1로만 되어 있거나 0으로 되어있으면 0, 1 출력
	// 그게 아니라면 재귀 호출

	// 2. 오른쪽 위 체크


	// 3. 왼쪽 아래 체크


	// 4. 오른쪽 아래 체크


	cout << ")";



}

int main() {

	cin >> n;
	string s;

	// 입력
	for (int i = 0; i < n;i++) {
		cin >> s;
		for (int j = 0; j < s.length(); j++)
			arr[i][j] = s[j]-'0';
	}

	QuadTree(0, n);



	return 0;
}
