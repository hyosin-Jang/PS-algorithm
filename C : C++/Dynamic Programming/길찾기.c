#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define M 100
#define N 100
#define max(x,y) ((x) > (y) ? (x): (y))

int map[M][N];
int path[M][N];

// 선호도(가중치)
int joy[M][N];


void calc_joy(int m, int n) {
	int i, j;
	joy[0][0] = map[0][0];

	for (i = 1; i < m; i++)
		joy[i][0] = joy[i - 1][0] + map[i][0];
		

	for (j = 1; j < n; j++)
		joy[0][j] = joy[0][j - 1] + map[0][j];

	for (i = 1; i < m; i++)
		for (j = 1; j < n; j++)
			joy[i][j] = max(joy[i - 1][j], joy[i][j - 1]) + map[i][j];


}

int calc_path(int m, int n) {
	int i, j;
	path[0][0] = map[0][0];

	for (i = 1; i < m; i++)
		if (map[i][0] == 0)
			path[i][0] = 0;
		else
			// 이전 값 들어오기
			path[i][0] = path[i - 1][0];

	for (j = 1; j < n; j++)
		if (map[0][j] == 0)
			path[0][j] = 0;
		else
			// 이전 값 들어오기
			path[0][j] = path[0][j-1];

	for (i = 1; i < m; i++)
		for (j = 1; j < n; j++)
		if (map[i][j] == 0)
			path[i][j] = 0;
		else
			path[i][j] = path[i -1][j] + path[i][j-1];


	// 경로의 수: 마지막 값 return
	return path[m - 1][n - 1];

}

int num_path(int m, int n) {
	if (map[m][n] == 0)
		return 0;
	if (m == 0 && n == 0)
		return 1;

	// true이면 전자, false면 후자 실행
	// a ? c:b
	return (m > 0 ? num_path(m - 1, n) : 0) + (n > 0 ? num_path(m, n - 1) : 0);

}

void print(int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			printf("%02d ", joy[i][j]);
		printf("\n");
	}
}


int main() {

	int m, n;
	scanf("%d %d",&m, &n);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &map[i][j]);

	//printf("%d\n", num_path(m-1, n-1));
	//printf("%d\n", calc_path(m , n));
	calc_joy(m, n);
	print(m, n);

	// calc_joy에서 최댓값 갖는 경로 찾는 것도 생각해보기!!
	return 0;
}