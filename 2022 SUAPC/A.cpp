#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int parent[1000001];
int cnt[1000001];
int answer[1000001];
long long ans=1;
// 부모 노드를 찾는 함수
int getParent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = getParent(parent[x]);

} 

// 두 부모 노드 합치는 함수
void unionParent(int a, int b) {
    // 각각의 부모를 찾고, 더 작은 쪽으로 합침
    a = getParent(a);
    b = getParent(b);
    if (a < b) {
        parent[b] = a;
        cnt[a]++;
    }
    else if (a == b)
        return;
    else { 
        parent[a] = b;
        cnt[b]++;
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        parent[i] = i; // 전부다 자기 자신 부모로 가리키도록만들어짐
        cnt[i] = 1;
    }
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        unionParent(a, b);
    }

    string s = "";
    for (int i =1 ; i <= N;i++) {
        if (parent[i])
        cout << "i: " << cnt[i] << "\n";
        ans *= (cnt[i] % 1000000007);
    }



     cout << ans << endl;
    
    return 0;
}
