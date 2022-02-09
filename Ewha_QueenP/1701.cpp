#include <iostream>
using namespace std;
const int MAX = 101;

int R, C, ZR, ZC;
char arr[MAX][MAX];

void solution() {

	for (int i = 0; i < R  ; i++) {
		for (int t = 0; t < ZR; t++) {
			for (int j = 0; j < C; j++) {

				for (int k = 0; k < ZC; k++) {
					cout << arr[i][j];
				}
			}
			cout << "\n";
		}
	}
}

int main() {

	cin >> R >> C >> ZR >> ZC;
	string s;
	// R행 C열 - 문자열이 주어짐!
	for (int i = 0; i < R; i++) {
		cin >> s;
		for (int j = 0; j < C; j++) {
			arr[i][j] = s[j];	
		}
	}

	solution();

	return 0;
}
