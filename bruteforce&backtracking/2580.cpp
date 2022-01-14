#include <iostream>
using namespace std;

const int MAX = 10;

int arr[MAX][MAX] = { 0, };

bool checkRow[MAX][MAX];
bool checkCol[MAX][MAX];
bool checkSquare[MAX][MAX];

// row행 col열이 속하는 작은 정사각형 구하기
int get_square(int row, int col) {
	return (row / 3) * 3 + (col / 3);
}


void print() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++)
			cout << arr[i][j] << " ";
		cout << "\n";
	}
	

}
// num번째 스도쿠 구하기
bool solve(int num) {
	// 마지막 칸인 경우, 출력 후 종료
	if (num == 81) {
		print();
		return true;
	}

	// 행, 열 구하기
	int x = num / 9; int y = num % 9;

	if (arr[x][y] != 0) {
		return solve(num + 1);
	}

	for (int i = 1; i < MAX; i++)
		if (!checkRow[x][i] && !checkCol[y][i] && !checkSquare[get_square(x, y)][i]) {
		
			checkRow[x][i] = true;
			checkCol[y][i] = true;
			checkSquare[get_square(x, y)][i] = true;
			arr[x][y] = i;

			if (solve(num + 1))
				return true;

			// 다시 돌려놓기 (백트래킹)
			checkRow[x][i] = false;
			checkCol[y][i] = false;
			checkSquare[get_square(x, y)][i] = false;
			arr[x][y] = 0;
		}

	return false;

}

int main() {

	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++) {
			cin >> arr[i][j];

			// 빈칸이 아닌 경우
			if (arr[i][j] != 0) {
				checkRow[i][arr[i][j]] = true;
				checkCol[j][arr[i][j]] = true;
				checkSquare[get_square(i, j)][arr[i][j]] = true;
			}
			
			}
		}

	// 0번 칸부터 채우기 시작
	Solve(0);

	return 0;
}
