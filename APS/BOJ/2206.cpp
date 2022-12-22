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
vector<Node> wall;

void input() {
  cin >> N >> M;
  board = vector<vector<int>>(N, vector<int>(M));
  string row;
  for (int i = 0; i < N; i++) {
    cin >> row;
    for (int j = 0; j < M; j++) {
      board[i][j] = row[j] - '0';
      if (board[i][j] == 1) wall.push_back({i, j});
    }
  }
}

vector<vector<int>> bfs(Node start) {
  vector<vector<int>> visited(N, vector<int>(M));
  visited[start.y][start.x] = 1;
  queue<Node> q;
  q.push(start);

  while (!q.empty()) {
    Node now = q.front();
    q.pop();

    for (int dir = 0; dir < 4; dir++) {
      int ny = now.y + dy[dir];
      int nx = now.x + dx[dir];
      if (!(0 <= ny && ny < N) || !(0 <= nx && nx < M)) continue;
      if (board[ny][nx] != 0) continue;
      if (visited[ny][nx] != 0) continue;
      visited[ny][nx] = visited[now.y][now.x] + 1;
      q.push({ny, nx});
    }
  }
  return visited;
}

void solve() {
  vector<vector<int>> dist_from_start = bfs({0, 0});
  vector<vector<int>> dist_from_end = bfs({N - 1, M - 1});

  int min_dist = INT_MAX;
  int start_to_middle, middle_to_end;
  for (int i = 0; i < wall.size(); i++) {
    Node middle = wall[i];
    start_to_middle = middle_to_end = INT_MAX;
    for (int dir = 0; dir < 4; dir++) {
      int ny = middle.y + dy[dir];
      int nx = middle.x + dx[dir];
      if (!(0 <= ny && ny < N) || !(0 <= nx && nx < M)) continue;
      if (dist_from_start[ny][nx] != 0)
        start_to_middle = min(start_to_middle, dist_from_start[ny][nx]);
      if (dist_from_end[ny][nx] != 0)
        middle_to_end = min(middle_to_end, dist_from_end[ny][nx]);
    }
    if (start_to_middle == INT_MAX || middle_to_end == INT_MAX) continue;
    min_dist = min(min_dist, start_to_middle + middle_to_end + 1);
  }
  if (dist_from_start[N - 1][M - 1] != 0)
    min_dist = min(min_dist, dist_from_start[N - 1][M - 1]);

  if (min_dist == INT_MAX) min_dist = -1;
  cout << min_dist;
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
N-by-M map
0 빈칸, 1 벽
(1,1) -> (N,M) 최단경로로 이동
시작 칸, 끝나는 칸 포함해서 센다.
벽 한개까지는 부술 수 있다.

1. 못가면 -1
2. 벽 안부수고 갈 수 있는 경로 -> 일반 floodfill
3. 벽 한번 부수고 갈 수 있는 경로
*/