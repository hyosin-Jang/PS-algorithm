#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 100001

int visited[MAX] = {0, };

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    queue<pair<int, int>> q;

    q.push({n, 0});

    int answer = 1;
    int quick = 1e9;

    if(n >= k){
        cout << n - k << "\n" << "1\n";
        return 0;
    }

    while(!q.empty()){
        int cur = q.front().first;
        int cnt = q.front().second;

        visited[cur] = 1; // 나올 때 방문 체크

        q.pop();

        if(cnt > quick) continue;
        
        if(cur == k){
            if (quick == cnt) answer++;
             else if (quick > cnt){
                // 지금까지 빠른 길보다 더 적은 횟수로 도착하면 갱신
                answer = 1;
                quick = cnt;
            }
            continue;
        }

        if(cur >= 1 && !visited[cur - 1]){
            q.push({cur - 1, cnt + 1});
        }
        if(cur + 1 <= MAX && !visited[cur + 1]){
            q.push({cur + 1, cnt + 1});
        }
        // 현재 숫자가 k보다 작은 경우에만 2배한 것 넣기
        if(cur <= k && cur * 2 <= MAX && !visited[cur * 2]){
            q.push({cur * 2, cnt + 1});
        }
    }

    cout << quick << "\n" << answer << "\n";

    return 0;
}