#include <iostream>

using namespace std;
const int MAX = 100 + 1;

int N, threeColorCnt=0, twoColorCnt=0;
string tmp; 

int visited[MAX][MAX] = { 0, };
int visited2[MAX][MAX] = { 0, };
int threeColor[MAX][MAX];
int twoColor[MAX][MAX];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

// 일반 사람 DFS
void DFS(int x, int y) {
	int nx, ny;
	int curColor;

	visited[x][y] = 1; // 방문 표시
	curColor = threeColor[x][y];

	// 상하좌우 검사
	for (int k = 0; k < 4; k++) {
		nx = x + dx[k]; // 다음 x위치
		ny = y + dy[k]; // 다음 y위치

		if (nx >= 0 && nx < N && ny >= 0 && ny < N) 
			if (threeColor[nx][ny] == curColor && !visited[nx][ny]) 
				DFS(nx, ny); // 다음 위치 방문 표시
	}
}

// 적록색약인 사람 DFS
void twoColorDFS(int x, int y) {
	int nx, ny;
	int curColor;

	visited2[x][y] = 1;
	curColor = twoColor[x][y];

	for (int k = 0; k < 4; k++) {
		nx = x + dx[k]; 
		ny = y + dy[k]; 

		if (nx >= 0 && nx < N && ny >= 0 && ny < N)
			if (twoColor[nx][ny] == curColor && !visited2[nx][ny])
				twoColorDFS(nx, ny); 
	}
}

int main() {

	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> tmp;
		for (int j = 0; j < tmp.length(); j++) {
			switch (tmp[j]) {
			case 'B':
				threeColor[i][j] = 2;
				twoColor[i][j] = 2;
				break;
			case 'R':
				threeColor[i][j] = 0;
				twoColor[i][j] = 0;
				break;
			case 'G':
				threeColor[i][j] = 1;
				twoColor[i][j] = 0;
				break;
			}
		}
		}

	// 일반사람 DFS
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (!visited[i][j])
			{
				DFS(i, j); // 지금 타고 들어갈 색깔
				threeColorCnt++;
			}

	// 적록색약 DFS
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (!visited2[i][j])
			{
				twoColorDFS(i, j);
				twoColorCnt++;
			}

	cout << threeColorCnt << " " << twoColorCnt << endl;


	return 0;
}
