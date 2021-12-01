#include <iostream>
#include <algorithm>

using namespace std;

#define INF 987654321

int graph[101][101];

void floyd(int n){
    for (int mid=1;mid<=n;mid++){
        for (int start=1;start<=n;start++){
            for (int end=1;end<=n;end++){
                if (graph[start][end] > graph[start][mid] + graph[mid][end])
                    graph[start][end] = graph[start][mid] + graph[mid][end];
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin >> n >> m;

    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            graph[i][j] = INF;
            if (i==j) graph[i][j] = 0;
        }
    }

    for (int i=0;i<m;i++){
        int node1, node2, w;
        cin >> node1 >> node2 >> w;
        graph[node1][node2] = min(graph[node1][node2],w);
    }

    floyd(n);

    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (graph[i][j] == INF)
                cout << 0 << " ";
            else
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
