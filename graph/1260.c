#define _CRT_SECURE_NO_WARNINGS
#define SIZE 1001
#include <stdio.h>

int arr[SIZE][SIZE] = { 0 };
int BFS_visit[SIZE] = { 0 };
int DFS_visit[SIZE] = { 0 };
int queue[SIZE];


//DFS
int DFS(int v, int N){
    // �湮�� ���� -> 1�� �ٲٱ�
    DFS_visit[v] = 1;
    printf("%d ", v);

    for (int i = 1; i <= N; i++)
        // ���� v�� ���������̰�, �湮���� �ʾҴٸ� �湮(��� ȣ��)
        if (arr[v][i] == 1 && DFS_visit[i] == 0)
            DFS(i, N);
        
    return 0;
}

//BFS
int BFS(int v, int N){
    int front = 0, rear = 0;
    int i, next_v;

    // �湮�� ���� -> 1�� �ٲٱ�
    BFS_visit[v] = 1;
    printf("%d ", v);

    // �������� enque
    queue[rear++] = v;

    while (front!= rear){
        next_v = queue[front++];
        for (i = 1; i <= N; i++)
            // ���������̰�, �湮���� �ʾҴٸ�
            if (arr[next_v][i] == 1 && BFS_visit[i] == 0){
                printf("%d ", i);

                // enque, �湮ǥ��
                queue[rear++] = i;
                BFS_visit[i] = 1;
            }
        }
    return 0;
}


int main(){
    int N, M, v, x, y;

    scanf("%d %d %d", &N, &M, &v);
    for (int i = 1; i <= M; i++){
        scanf("%d %d", &x, &y);
        arr[x][y] = 1; // ����� ����
        arr[y][x] = 1;
    }

    DFS(v, N);
    printf("\n");
    BFS(v, N);

    return 0;
}