#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 2147000000
using namespace  std;

int a, b, n, m;
 // ����� �׷���
vector<pair<int, int>> graph[10001];
int d[1001];

//���ͽ�Ʈ�� �˰���
void dijkstar(int start) {
    priority_queue<pair<int, int>>pq;
    //�������� ���� �̵���� 0 �� �������� ���� ��带 �ִ´�.
    pq.push({ 0,start });
    //ó�� ���ڿ��� ������ ���ڷ� ���� �ּ� ġȯ Ƚ���� 0�̴�.
    d[start] = 0;
    //pq�� empty�� �ƴҶ� ����
    while (!pq.empty()) {
        //�ش� ���� ���� ���� ���� ��밪
        //pq�� ����� ������ �ٲ� �־��� ������ cost���� ���� �� -�� ���̰� ���� ������.
        int cost = -pq.top().first;
        //���� ���
        int now = pq.top().second;
        pq.pop();
        //�̹� �湮�� ����� ��� ����
        if (cost > d[now]) {
            continue;
        }
        //�� �׷����� ����� ��带 Ȯ���Ѵ�.
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
        //s���� e�� �����ϴµ� �ɸ��� Ƚ��
        //����� �̴�
        graph[s].push_back({ e,1 });
        graph[e].push_back({ s,1 });
    }

    dijkstar(a);

    //ġȯ ������ ���
    if (d[b] != INF) {
        cout << d[b] << "\n";
    }
    //ġȯ �Ұ����� ���
    else {
        cout << -1 << "\n";
    }

    return 0;
}