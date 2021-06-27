#include <stdio.h>
#define S 50

int M, D, R = 0, P[S], C[S][S], N[S] = { 0, };
// 루트부터 자식노드 찾아 dfs돌면서
// 리프노드면 count++
// c는 각 노드들의 자식 노드들에 대한 인접리스트
// n은 각 노드들의 자식 노드 수
int dfs(int i) {
    int r = 0;
    if (P[i] != -2) {
        if (N[i])
            for (int c = 0; c < N[i]; c++)
                r += dfs(C[i][c]);
        if (!r)
            r = 1;
    }
    return r;
}

int main() {
    scanf("%d", &M);

    for (int i = 0; i < M; i++) {
        scanf("%d", &P[i]);

        C[P[i]][N[P[i]]++] = i;

        if (P[i] == -1)
            R = i;
    }
    scanf("%d", &D);
    P[D] = -2;
    printf("%d\n", dfs(R));
    return 0;
}