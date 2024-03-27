#include <string.h>

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N, M, ret = 0;
int a[10][10], visited[10][10];
vector<pair<int, int>> wall, virus;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};

void dfs(int cx, int cy) {
  for (int i = 0; i < 4; i++) {
    int nx = cx + dx[i];
    int ny = cy + dy[i];

    if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

    // 방문했거나 벽이 있다면 다음으로 넘어가기
    if (visited[nx][ny] == 1 || a[nx][ny] == 1) continue;

    visited[nx][ny] = 1;  // 방문 표시
    dfs(nx, ny);
  }
}

// 바이러스 퍼뜨리고 안전영역 개수 리턴하는 함수
int go() {
  int cnt = 0;
  memset(visited, 0, sizeof(visited));

  // 각 바이러스 퍼뜨리기
  for (pair<int, int> v : virus) {
    visited[v.first][v.second] = 1;

    dfs(v.first, v.second);  // 퍼뜨리기
  }

  // 안전영역 개수 세어주기
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (a[i][j] == 0 && visited[i][j] == 0) {
        cnt++;
      }
    }
  }

  return cnt;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> a[i][j];
      if (a[i][j] == 0) wall.push_back({i, j});
      if (a[i][j] == 2) virus.push_back({i, j});
    }
  }

  // 3중 for문으로 벽3개 세우기
  int l = wall.size();

  for (int i = 0; i < l; i++) {
    for (int j = 0; j < i; j++) {
      for (int k = 0; k < j; k++) {
        a[wall[i].first][wall[i].second] = 1;
        a[wall[j].first][wall[j].second] = 1;
        a[wall[k].first][wall[k].second] = 1;

        ret = max(ret, go());

        a[wall[i].first][wall[i].second] = 0;  // 원복
        a[wall[j].first][wall[j].second] = 0;
        a[wall[k].first][wall[k].second] = 0;
      }
    }
  }

  cout << ret << "\n";

  return 0;
}