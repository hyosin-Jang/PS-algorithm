#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const long long INF = 1e18; // 절대 나올 수 없는 경로값

int main() {
    int N, M;
    long long dist[500];
    scanf("%d %d", &N, &M);
    vector<P> adj[500];
    for (int i = 0; i < M; i++) {
        int A, B, C;
        scanf("%d %d %d", &A, &B, &C);
        adj[A - 1].push_back(P(B - 1, C));
    }
    fill(dist, dist + N, INF);
    dist[0] = 0;
    for (int i = 0; i < N - 1; i++) { // (N-1)번의 루프
        for (int j = 0; j < N; j++) {
            // N-1번의 루프에 걸쳐 각 정점이 i+1개 정점을 거쳐오는 최단경로 갱신
            for (auto& p : adj[j]) {
                int next = p.first, d = p.second;
                if (dist[j] != INF && dist[next] > dist[j] + d) {
                    dist[next] = dist[j] + d;
                }
            }
        }
    }
    for (int i = 1; i < N; i++)
        printf("%lld\n", dist[i] != INF ? dist[i] : -1);
}