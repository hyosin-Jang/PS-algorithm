#define _CRT_SECURE_NO_WARNINGS
#define SIZE 1001
#include <stdio.h>
#define SIZE 101
int arr[SIZE][SIZE] = {0};
int DFS_visit[SIZE] = { 0 };
int cnt = 0;

//DFS
int DFS(int v, int N){
    // �湮�� ���� -> 1�� �ٲٱ�
    DFS_visit[v] = 1;

    for (int i = 1; i <= N; i++)
        // ���� v�� ���������̰�, �湮���� �ʾҴٸ� �湮(��� ȣ��)
		if (arr[v][i] == 1 && DFS_visit[i] == 0) {
			cnt++;
			DFS(i, N);

		}
    return cnt;
}
int main() {
	int num, e, x, y;
	scanf("%d", &num); //��ǻ���� ��
	scanf("%d",&e); // ������ ��

	for (int i = 0; i < e; i++) {
		scanf("%d %d", &x, &y);
		arr[x][y] = 1;
		arr[y][x] = 1;
	}

	printf("%d\n",DFS(1, num));

	return 0;
}