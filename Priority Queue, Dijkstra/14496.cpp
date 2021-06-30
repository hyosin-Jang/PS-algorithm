#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 2147000000
using namespace  std;

int a, b, n, m;
 // 양방향 그래프
vector<pair<int, int>> graph[10001];
int d[1001];

//다익스트라 알고리즘
void dijkstar(int start) {
    priority_queue<pair<int, int>>pq;
    //시작점에 대한 이동비용 0 과 시작점에 대한 노드를 넣는다.
    pq.push({ 0,start });
    //처음 문자에서 동일한 문자로 가는 최소 치환 횟수는 0이다.
    d[start] = 0;
    //pq가 empty가 아닐때 까지
    while (!pq.empty()) {
        //해당 노드로 가기 까지 위한 비용값
        //pq에 저장시 음수로 바꿔 넣었기 때문에 cost값을 꺼낼 때 -를 붙이고 값을 꺼낸다.
        int cost = -pq.top().first;
        //현재 노드
        int now = pq.top().second;
        pq.pop();
        //이미 방문한 노드인 경우 생략
        if (cost > d[now]) {
            continue;
        }
        //각 그래프의 연결된 노드를 확인한다.
        for (int i = 0;i < graph[now].size();i++) {
            int c = cost + graph[now][i].second;
            if (c < d[graph[now][i].first]) {
                d[graph[now][i].first] = c;
                pq.push({ -c,graph[now][i].first });
            }
        }
    }
}

int main() {

    cin.tie(0);
    cout.tie(0);
    std::ios::sync_with_stdio(false);

    cin >> a >> b >> n >> m;
    fill(d, d + 1001, INF);

    for (int i = 0;i < m;i++) {
        int s, e;
        cin >> s >> e;
        //s에서 e로 변겅하는데 걸리는 횟수
        //양방향 이다
        graph[s].push_back({ e,1 });
        graph[e].push_back({ s,1 });
    }

    dijkstar(a);

    //치환 가능한 경우
    if (d[b] != INF) {
        cout << d[b] << "\n";
    }
    //치환 불가능한 경우
    else {
        cout << -1 << "\n";
    }

    return 0;
}