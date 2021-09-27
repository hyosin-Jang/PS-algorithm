#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
const int MAX = 50 + 1;
int graph[MAX][MAX];
int visited[MAX][MAX];
int w, h;

// 12, 1, 3, 5, 6, 8, 9, 10
int X[8] = {-1, -1, 0, 1, 1, 1, 0, -1 };
int Y[8] = { 0,  1, 1, 1, 0, -1, -1, -1 };


void countLandNum(int y, int x) {
	
	if (!graph[y][x] || visited[y][x])
		return;

	visited[y][x] = 1;


	for (int i = 0; i < 8; i++) {
		int nextX = x + X[i];
		int nextY = y + Y[i];

		if (nextX >= 0 && nextX < w &&
			nextY >= 0 && nextY < h) 
			countLandNum(nextY, nextX);

	}
	
}


int main() {
	
	while (1) {
		cin >> w >> h;

		if (w == 0 && h == 0)
			break;

		memset(visited, false, sizeof(visited));

	
		for (int i = 0; i < h; i++) 
			for (int j = 0; j < w; j++)
				cin >> graph[i][j];

		int cnt = 0;

		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				
				if (!visited[i][j] && graph[i][j]) {
					cnt++;
					countLandNum(i, j);
				}
		cout << cnt << "\n";
	}

	return 0;
}
