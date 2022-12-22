#include <limits.h>

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int y, x;
};

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};

int N, M;
vector<vector<int>> board;
vector<vector<vector<int>>> visited;
vector<Node> virus;
vector<int> activate;
int min_time;

void input() {
  cin >> N >> M;
  board.resize(N, vector<int>(N));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
      if (board[i][j] == 2) virus.push_back({i, j});
    }
  }
  visited.resize(virus.size(), vector<vector<int>>(N, vector<int>(N, INT_MAX)));
  min_time = INT_MAX;
}

void bfs(Node& start, vector<vector<int>>& visited_now) {
  queue<Node> q;
  q.push(start);
  visited_now[start.y][start.x] = 0;

  int debug = 0;

  while (!q.empty()) {
    Node now = q.front();
    q.pop();

    for (int dir = 0; dir < 4; dir++) {
      int ny = now.y + dy[dir];
      int nx = now.x + dx[dir];
      if (!(0 <= ny && ny < N) || !(0 <= nx && nx < N)) continue;
      if (board[ny][nx] == 1) continue;
      if (visited_now[ny][nx] != INT_MAX) continue;
      visited_now[ny][nx] = visited_now[now.y][now.x] + 1;
      q.push({ny, nx});
    }
  }
}

int spread_virus() {
  int time_local, time_global = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (board[i][j] != 0) continue;
      time_local = INT_MAX;
      for (int k = 0; k < M; k++) {
        time_local = min(time_local, visited[activate[k]][i][j]);
      }
      time_global = max(time_global, time_local);
    }
  }
  return time_global;
}

void dfs(int now) {
  // base case
  if (activate.size() == M) {
    min_time = min(min_time, spread_virus());
    return;
  }
  if (now == virus.size()) return;
  // recursive case
  activate.push_back(now);
  dfs(now + 1);
  activate.pop_back();
  dfs(now + 1);
}

void solve() {
  for (int i = 0; i < virus.size(); i++) {
    bfs(virus[i], visited[i]);
  }
  dfs(0);
  if (min_time == INT_MAX) min_time = -1;
  cout << min_time;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}

/*
바이러스 : 활성 / 비활성 상태
활성상태 : 1초동안 상하좌우로 복제
M개를 활성상태로 변경
NxN 연구소
빈칸, 벽, 바이러스

연구소의 모든 빈 칸에 바이러스가 있게 되는 최소시간
*/