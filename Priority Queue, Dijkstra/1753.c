#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define S 20001
#define INF 12
#define min(x, y) ((x) < (y) ? (x) : (y))

int W[S][S];
int found[S]; // 방문한 정점 표시 0=false,1=true
int distance[S]; // 시작정점으로부터의 최단경로 거리

int choose(int n) {
	int i, min, minpos;
	min = 12;
	minpos = -1;
	for(i=1 ; i<= n ; i++)
		if (distance[i] < min && !found[i]) {
			min = distance[i];
			minpos = i;
		}
	return minpos;
}

void shortest_path(int V, int K) {
	// distance 배열 초기화
	int i, u, weight;
	W[K][K] = 0;
	for (i = 1; i <= V; i++) {
		distance[i] = W[K][i];
		found[i] = 0; // false로 초기화
	}
	found[K] = 1;
	distance[K] = 0; // 자기자신은 0
	
	for (i = 1; i <= V; i++) {
		u = choose(V);
		//printf("u: %d\n", u);
		found[u] = 1; // 방문했다고 표시
		for (weight = 1; weight <= V; weight++)
			if (!found[weight]) // 가중치 갱신
				if (distance[u] + W[u][weight] < distance[weight])
					distance[weight] = distance[u] + W[u][weight];
	}
}


int main() {
	int V, E, K, u, v, w;

	scanf("%d %d", &V, &E); // 정점, 간선 개수
	getchar();
	scanf("%d", &K); // 시작정점
	getchar();

	for (int i = 1; i <= V; i++)
		for (int j = 1; j <= V; j++)
			W[i][j] = INF; //INF로 초기화

	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &u, &v, &w);
		getchar();
		if (W[u][v] == 0)
			W[u][v] = w;
		else
			W[u][v] = min(W[u][v], w);
	}
	for (int i =1 ; i<= V ; i++) {
		for (int j = 1; j <= V; j++) 
			printf("%d ", W[i][j]);
		printf("\n");
	}

	shortest_path(V, K);

	for (int i = 1; i <= V; i++) {
		if (i != K && distance[i] == 0)
			printf("INF\n");
		else
			printf("%d\n", distance[i]);
	}
	
	return 0;
}
