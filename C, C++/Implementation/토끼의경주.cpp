#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;

#define MAX_P 2000 + 2

struct rabbit {
  int idx;       // i번 토끼 (인덱스)
  int id;        // 고유번호
  int jump_cnt;  // 현재까지 총 점프 횟수
  int r, c;      // 현재 위치
};

int jump_cnt[MAX_P];          // 현재까지 점프 횟수
pair<int, int> point[MAX_P];  // 현재 위치
long long scores[MAX_P] = {0};
int dists[MAX_P] = {0};

map<int, int> id_to_idx;
map<int, int> idx_to_id;
bool is_moved[MAX_P];

int N, M, P, Q;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

struct cmp {
  bool operator()(rabbit& r1, rabbit& r2) {
    if (r1.jump_cnt == r2.jump_cnt) {
      if (r1.r + r1.c == r2.r + r2.c) {
        if (r1.r == r2.r) {
          if (r1.c == r2.c) {
            return r1.id > r2.id;
          }
          return r1.c > r2.c;
        }
        return r1.r > r2.r;
      }
      return r1.r + r1.c > r2.r + r2.c;
    }
    return r1.jump_cnt > r2.jump_cnt;
  }
};

bool inRange(int x, int y) { return x >= 1 && x <= N && y >= 1 && y <= M; }

bool cmp2(pair<int, int>& p1, pair<int, int>& p2) {
  if (p1.first + p1.second == p2.first + p2.second) {
    if (p1.first == p2.first) {
      return p1.second > p2.second;
    }
    return p1.first > p2.first;
  }
  return p1.first + p1.second > p2.first + p2.second;
}

bool cmp3(rabbit& r1, rabbit& r2) {
  if (r1.r + r1.c == r2.r + r2.c) {
    if (r1.r == r2.r) {
      if (r1.c == r2.c) {
        return r1.c > r2.c;
      }
      return r1.id > r2.id;
    }
    return r1.r > r2.r;
  }
  return r1.r + r1.c > r2.r + r2.c;
}

void raceStart(int K, int S) {
  // 가장 우선순위가 높은 토끼를 뽑아 멀리 보내주는 것을 K번 반복한다.

  for (int i = 1; i <= P; i++) is_moved[i] = false;

  priority_queue<rabbit, vector<rabbit>, cmp> rabbit_pq;

  for (int i = 1; i <= P; i++) {
    rabbit_pq.push(
        {i, idx_to_id[i], jump_cnt[i], point[i].first, point[i].second});
  }

  for (int i = 0; i < K; i++) {
    // 우선순위 조건에 따라 토끼를 선정한다.
    rabbit cur = rabbit_pq.top();
    rabbit_pq.pop();
    vector<pair<int, int>> next;

    int cx = cur.r, cy = cur.c, idx = cur.idx;
    int dist = dists[idx];

    for (int d = 0; d < 4; d++) {
      // d 방향으로 dist만큼 이동했을 때 위치를 구해서 next에 넣어준다.
      int cur_dist = dist;

      int nx = cx, ny = cy;
      int cur_d = d;

      if (d == 0 || d == 2) cur_dist %= ((N - 1) * 2);
      if (d == 1 || d == 3) cur_dist %= ((M - 1) * 2);

      // dist칸을 이동시킨다.
      nx += dx[cur_d] * cur_dist;
      ny += dy[cur_d] * cur_dist;

      while (nx < 1 || nx > N || ny < 1 || ny > M) {
        if (nx < 1) nx = (2 - nx);
        if (ny < 1) ny = (2 - ny);
        if (nx > N) nx = 2 * N - nx;
        if (ny > M) ny = 2 * M - ny;
      }

      next.push_back({nx, ny});
    }
    sort(next.begin(), next.end(), cmp2);
    pair<int, int> next_pos = next[0];

    long long cur_score = next_pos.first + next_pos.second;

    // 갱신된 위치를 반영한다.
    jump_cnt[cur.idx]++;
    point[cur.idx] = next_pos;
    is_moved[cur.idx] = true;

    // 해당 칸으로 토끼를 이동한다.
    rabbit_pq.push(
        {cur.idx, cur.id, cur.jump_cnt + 1, next_pos.first, next_pos.second});
    ;

    // cur.num을 제외한 토끼들 모두 r+c만큼 점수 획득
    for (int p = 1; p <= P; p++)
      if (p != cur.idx) scores[p] += cur_score;
  }

  rabbit pr = {-1, -1, -1, -1, -1};

  while (!rabbit_pq.empty()) {
    rabbit cur = rabbit_pq.top();
    rabbit_pq.pop();

    if (!is_moved[cur.idx]) continue;

    if (pr.r + pr.c == cur.r + cur.c) {
      if (pr.r == cur.r) {
        if (pr.c == cur.c) {
          if (pr.id < cur.id) pr = cur;
        } else if (pr.c < cur.c)
          pr = cur;
      } else if (pr.r < cur.r)
        pr = cur;
    } else if (pr.r + pr.c < cur.r + cur.c)
      pr = cur;
  }

  scores[pr.idx] += S;
}

void changeDist(int p_id, int L) {
  int idx = id_to_idx[p_id];
  dists[idx] *= L;
}

long long chooseBestRabbit() {
  long long max_score = 0;
  for (int i = 1; i <= P; i++) {
    if (max_score < scores[i]) max_score = scores[i];
  }
  return max_score;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> Q;

  for (int i = 0; i < Q; i++) {
    int op;
    cin >> op;
    switch (op) {
      case 100: {
        cin >> N >> M >> P;
        int p_id, d;
        for (int p = 1; p <= P; p++) {
          cin >> p_id >> d;

          // 초기 정보를 세팅한다.
          point[p] = make_pair(1, 1);
          dists[p] = d;
          id_to_idx[p_id] = p;
          idx_to_id[p] = p_id;
        }
        break;
      }
      case 200: {
        int K, S;
        cin >> K >> S;
        raceStart(K, S);
        break;
      }
      case 300: {
        int p_id, L;
        cin >> p_id >> L;
        changeDist(p_id, L);
        break;
      }
      case 400: {
        cout << chooseBestRabbit() << "\n";
        break;
      }
    }
  }

  return 0;
}