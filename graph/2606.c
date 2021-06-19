#define _CRT_SECURE_NO_WARNINGS
#define SIZE 1001
#include <stdio.h>
#define SIZE 101
int arr[SIZE][SIZE] = {0};
int DFS_visit[SIZE] = { 0 };
int cnt = 0;

//DFS
int DFS(int v, int N){
    // 방문한 정점 -> 1로 바꾸기
    DFS_visit[v] = 1;

    for (int i = 1; i <= N; i++)
        // 정점 v의 인접정점이고, 방문하지 않았다면 방문(재귀 호출)
		if (arr[v][i] == 1 && DFS_visit[i] == 0) {
			cnt++;
			DFS(i, N);

		}
    return cnt;
}
int main() {
	int num, e, x, y;
	scanf("%d", &num); //컴퓨터의 수
	scanf("%d",&e); // 간선의 수

	for (int i = 0; i < e; i++) {
		scanf("%d %d", &x, &y);
		arr[x][y] = 1;
		arr[y][x] = 1;
	}

	printf("%d\n",DFS(1, num));

	return 0;
}