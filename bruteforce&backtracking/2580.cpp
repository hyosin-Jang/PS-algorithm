#include <iostream>
using namespace std;

const int MAX = 9;

int arr[MAX][MAX] = { 0, };

int visited[MAX] = { 0, };

int checkRow(int r, int c) {
	// 채우면 1, 못채우면 0 반환
	int flag;

	for (int i = 0; i < MAX; i++)
		visited[arr[r][i]] = 1;

	for(int i=0 ; i< MAX ; i++)
		if ()
}

int checkCol(int i, int j) {
	// 채우면 1, 못채우면 0 반환

}
int check3x3(int i, int j) {
	// 채우면 1, 못채우면 0 반환

}

void Solution() {
	int rRow, rCol, r3x3;
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++) {
			if (arr[i][j] == 0) {
				rRow = checkRow(i, j);
				if (rRow == 1)
					continue;
				rCol = checkCol(i, j);
				if (rCol == 1)
					continue;
				r3x3 = check3x3(i, j);
			
			
			}
		}

}

int main() {

	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			cin >> arr[i][j];

	Solution();



	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++)
			cout << arr[i][j] << " ";
		cout << "\n";
	}




	return 0;
}
