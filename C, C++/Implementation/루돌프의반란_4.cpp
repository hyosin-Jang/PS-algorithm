#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;

#define MAX_P 30 + 2
#define MAX_N 50 + 2
typedef tuple<int, int, int, int> tiii;

// 보드크기, M라운드, 산타수, 루돌프힘, 산타힘
int N, M, P, C, D;

pair<int, int> deer;

struct santa {
  int num, r, c, wakeup_round;
  bool live, sleep;
};

int score[MAX_P];
int board[MAX_N][MAX_N];
santa santas[MAX_P];

int getDist(int r1, int c1, int r2, int c2) {
  return (r1 - r2) * (r1 - r2) + (c1 - c2) * (c1 - c2);
}

struct cmp {
  bool operator()(santa& s1, santa& s2) {
    int dist1 = getDist(s1.r, s1.c, deer.first, deer.second);
    int dist2 = getDist(s2.r, s2.c, deer.first, deer.second);

    if (dist1 == dist2) {
      if (s1.r == s2.r) return s1.c < s2.c;
      return s1.r < s2.r;
    }
    return dist1 > dist2;
  }
};

// 거리, nx, ny, nd
bool cmp2(tiii& t1, tiii& t2) {
  // 거리 작은 순, 거리 같다면 d 작은 순
  int dist1, d1, dist2, d2;
  tie(dist1, ignore, ignore, d1) = t1;
  tie(dist2, ignore, ignore, d2) = t2;

  if (dist1 == dist2) return d1 < d2;

  return dist1 < dist2;
};

// 12시부터 시계방향
int d_dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int d_dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

// 상우하좌 순서
int s_dx[] = {-1, 0, 1, 0};
int s_dy[] = {0, 1, 0, -1};

bool inRange(int x, int y) { return x >= 1 && x <= N && y >= 1 && y <= N; }

// (r, c)에서 santa_num1 -> santa_num2로 충돌한 상태
void runInteraction(int santa_num1, int santa_num2, int r, int c, int d,
                    bool santa_dir) {
  // 산타 앉혀주기
  board[r][c] = santa_num1;
  santas[santa_num1].r = r;
  santas[santa_num1].c = c;

  int nx, ny;

  if (santa_dir) {
    nx = r + s_dx[d];
    ny = c + s_dy[d];
  } else {
    nx = r + d_dx[d];
    ny = c + d_dy[d];
  }

  // 격자밖이면 탈락시킨다.
  if (!inRange(nx, ny))
    santas[santa_num2].live = false;
  else {
    // 격자 안이면 해당 위치에 다른 산타 있는지 확인한다.
    int interaction_santa = board[nx][ny];

    // 다른 산타가 있는 경우
    if (interaction_santa > 0)
      runInteraction(santa_num2, interaction_santa, nx, ny, d, santa_dir);

    // 다른 산타가 없는 경우
    else {
      board[nx][ny] = santa_num2;
      santas[santa_num2].r = nx;
      santas[santa_num2].c = ny;
    }
  }
}
void moveDeer(int round) {
  priority_queue<santa, vector<santa>, cmp> santa_pq;

  for (int i = 1; i <= P; i++)
    if (santas[i].live) santa_pq.push(santas[i]);

  santa target_santa = santa_pq.top();

  // 8방향 중 해당 산타와 가장 가까워지는 방향을 구한다.
  int sx = target_santa.r, sy = target_santa.c;

  int prev_santa_deer_dist = getDist(sx, sy, deer.first, deer.second);

  int next_r, next_c, next_d;

  for (int d = 0; d < 8; d++) {
    int nx = deer.first + d_dx[d];
    int ny = deer.second + d_dy[d];

    if (!inRange(nx, ny)) continue;

    int cur_dist = getDist(sx, sy, nx, ny);

    // 현재 거리보다 더 가까워진다면
    if (prev_santa_deer_dist > cur_dist) {
      next_r = nx, next_c = ny, next_d = d;
      prev_santa_deer_dist = cur_dist;
    }
  }

  // 사슴 이동시킨다.
  deer = make_pair(next_r, next_c);

  // 이동시킨 자리에 타겟 산타가 있는지 확인한다.
  if (deer == make_pair(sx, sy)) {
    // 해당 산타 점수 획득한다.
    score[target_santa.num] += C;

    // 기절시킨다.
    santas[target_santa.num].sleep = true;
    santas[target_santa.num].wakeup_round = round + 2;

    // 루돌프 방향대로 C칸 이동시킨다.
    board[sx][sy] = 0;

    int next_sx = sx + C * d_dx[next_d];
    int next_sy = sy + C * d_dy[next_d];

    // 격자 밖인 경우 죽인다.
    if (!inRange(next_sx, next_sy))
      santas[target_santa.num].live = false;
    else {
      // 격자 안인 경우 해당 위치에 다른 산타가 있는지 확인한다.
      int interaction_santa = board[next_sx][next_sy];

      // 다른 산타가 있는 경우
      if (interaction_santa > 0)
        runInteraction(target_santa.num, interaction_santa, next_sx, next_sy,
                       next_d, false);

      // 다른 산타가 없는 경우 해당 위치에 안착시킨다.
      else {
        board[next_sx][next_sy] = target_santa.num;
        santas[target_santa.num].r = next_sx;
        santas[target_santa.num].c = next_sy;
      }
    }
  }
}

bool isAllDead() {
  for (int i = 1; i <= P; i++) {
    if (santas[i].live) return false;
  }
  return true;
}

void moveSantas(int round) {
  for (int i = 1; i <= P; i++) {
    if (!santas[i].live) continue;

    // 기절한 경우 깨어날 라운드인지 체크한다.
    if (santas[i].sleep && santas[i].wakeup_round == round)
      santas[i].sleep = false;

    if (santas[i].sleep) continue;

    vector<tiii> v;

    int sx = santas[i].r, sy = santas[i].c, snum = santas[i].num;

    int cur_dist = getDist(sx, sy, deer.first, deer.second);

    for (int d = 0; d < 4; d++) {
      int nx = sx + s_dx[d];
      int ny = sy + s_dy[d];

      // 격자밖이거나 다른 산타가 있는 경우 못간다.
      if (!inRange(nx, ny)) continue;
      if (board[nx][ny] > 0) continue;

      int next_dist = getDist(nx, ny, deer.first, deer.second);

      //  현재 방향보다 가까운 경우 넣어준다.
      if (cur_dist > next_dist)
        // 거리, nx, ny, nd
        v.push_back({next_dist, nx, ny, d});
    }
    if (v.size() == 0) continue;

    sort(v.begin(), v.end(), cmp2);

    int next_r, next_c, next_d;
    tie(ignore, next_r, next_c, next_d) = v[0];

    // 위치 업데이트 시켜준다.
    santas[i].r = next_r;
    santas[i].c = next_c;

    board[sx][sy] = 0;
    board[next_r][next_c] = snum;

    // 다음 칸에 루돌프가 있는지 확인한다.
    if (deer == make_pair(next_r, next_c)) {
      score[snum] += D;

      // 기절시킨다.
      santas[snum].sleep = true;
      santas[snum].wakeup_round = round + 2;

      // 현재 루돌프랑 부딪힌 위치 없애준다.
      board[next_r][next_c] = 0;

      // 산타가 이동한 반대 방향으로 D만큼 이동시킨다.
      int move_dir = (next_d + 2) % 4;

      int nx = next_r + D * s_dx[move_dir];
      int ny = next_c + D * s_dy[move_dir];

      // 격자 밖인 경우
      if (!inRange(nx, ny))
        santas[snum].live = false;
      else {
        // 격자 안인경우, 다른 산타가 위치해 있으면
        // 격자 안인 경우 해당 위치에 다른 산타가 있는지 확인한다.
        int interaction_santa = board[nx][ny];

        // 다른 산타가 있는 경우
        if (interaction_santa > 0)
          runInteraction(snum, interaction_santa, nx, ny, move_dir, true);

        // 다른 산타가 없는 경우
        else {
          board[nx][ny] = snum;
          santas[snum].r = nx;
          santas[snum].c = ny;
        }
      }
    }
  }
}

void addScore() {
  for (int i = 1; i <= P; i++) {
    if (santas[i].live) score[i]++;
  }
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M >> P >> C >> D;
  cin >> deer.first >> deer.second;

  int pn, sr, sc;
  for (int i = 0; i < P; i++) {
    cin >> pn >> sr >> sc;

    santa tmp = {pn, sr, sc, 0, true, false};
    santas[pn] = tmp;
    board[sr][sc] = pn;
  }

  for (int round = 1; round <= M; round++) {
    // Step 1. 사슴을 움직인다.
    moveDeer(round);

    // 모두 죽었는지 체크한다.
    if (isAllDead()) break;

    // Step 2. 산타를 움직인다.
    moveSantas(round);

    if (isAllDead()) break;

    // Step 3. 살아있는 산타는 점수를 추가한다.
    addScore();
  }

  for (int i = 1; i <= P; i++) {
    cout << score[i] << " ";
  }
  cout << "\n";

  return 0;
}