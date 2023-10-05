#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

// 39분 - 2트 solve
// 1트 32%에서 틀림: 편향 트리의 경우 루트노드도 리프노드가 될 수 있음 => 리프노드에 추가해서 해결

// [처음 아이디어]
// 1. 한 노드에서 다른 모든 노드까지 경로를 탐색하니까 다익스트라로 풀면 안되나?
// - 다익스트라는 한번에 O(NlogN) => 이를 N번 수행하면 O(N^2logN)이 되고, 2초 내에 수행할 수 없음
// - 일반 그래프가 아닌 트리라는 점을 이용하자. 더 효율적인 풀이가 있음
// (참고: 다익스트라 메모리초과: https://www.acmicpc.net/board/view/59780)

// 2. 리프 노드들 간의 경로를 구한 후 최댓값 갱신
// - 트리의 지름이 될 수 있는 건 리프 노드들 간의 경로다. (지름의 끝이 중간 노드가 될 수는 없음)
// - 따라서, 리프 노드들을 vector에 따로 저장해주고, 
// - 인접 노드들을 dfs 탐색 후 리프 노드 방문 시 최대 길이 갱신하자.

int N;
vector<vector<pair<int, int>>> tree(10001); // 부모 -> 자식 인접 노드 저장 {노드, 가중치}
vector<vector<pair<int, int>>> reverse_tree(10001); // 자식 -> 부모 인접 노드 저장
vector<int> leaves;
int visited[10001] = {0};
int leaf[10001] = {0};
int max_weight = 0;

void dfs(int node, int weight){

    // 시작 노드가 아닌데, leaf노드에 도착한 경우 최댓값으로 갱신
    if(weight != 0 && leaf[node]){
        max_weight = max(max_weight, weight);
        return;
    }
    // node와 윗방향으로 인접한 node 방문
    for(int i = 0 ; i < reverse_tree[node].size() ; i++){
        int adjacent = reverse_tree[node][i].first;
        if(!visited[adjacent]){
            visited[adjacent] = 1;
            int cur_weight = reverse_tree[node][i].second;
            dfs(adjacent, weight + cur_weight);
        }
    }
    // node와 아랫방향으로 인접한 node 방문
    for(int i = 0 ; i < tree[node].size() ; i++){
        int adjacent = tree[node][i].first;
        if(!visited[adjacent]){
            visited[adjacent] = 1;
            int cur_weight = tree[node][i].second;
            dfs(adjacent, weight + cur_weight);
        }
    }
}
int main(void){

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int parent, child, weight;

    cin >> N;

    // 리프 노드에서 리프 노드를 만날 때까지 dfs 수행 후, 가장 긴 경로 갱신 후 출력
    for(int i = 0 ; i< N-1  ; i++){
        cin >> parent >> child >> weight;
        tree[parent].push_back({child, weight});
        reverse_tree[child].push_back({parent, weight});
    }

    // leaf 노드인지 확인
    for(int i = 1 ; i<= N ; i++){
        bool is_leaf = true;
        if(tree[i].size() == 0) {
            leaf[i] = 1;
            leaves.push_back(i); // child 없는 경우 leaf 노드로 간주
        }
    }

    // 만약 편향트리인 경우 루트노드도 리프노드가 되므로 leaves에 추가
    if(tree[1].size() == 1){
        leaf[1] = 1;
        leaves.push_back(1);
    }
    for(int i= 0 ; i <leaves.size() ; i++){
        memset(visited, 0, sizeof(visited));
        visited[leaves[i]] = 1;
        dfs(leaves[i], 0);
    }

    cout << max_weight << "\n";

    return 0;
}