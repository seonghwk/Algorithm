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

int height, width;
vector<vector<int>> board;

void input() {
  cin >> height >> width;
  board = vector<vector<int>>(height, vector<int>(width));
  string row;
  for (int i = 0; i < height; i++) {
    cin >> row;
    for (int j = 0; j < width; j++) {
      if (row[j] == 'L') board[i][j] = 1;
    }
  }
}

int bfs(Node start) {
  vector<vector<int>> visited(height, vector<int>(width));
  visited[start.y][start.x] = 1;
  queue<Node> q;
  q.push(start);

  int max_dist = 0;

  while (!q.empty()) {
    Node now = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int ny = now.y + dy[i];
      int nx = now.x + dx[i];
      if (!(0 <= ny && ny < height) || !(0 <= nx && nx < width)) continue;
      if (board[ny][nx] == 0) continue;
      if (visited[ny][nx] != 0) continue;
      visited[ny][nx] = visited[now.y][now.x] + 1;
      max_dist = max(max_dist, visited[ny][nx]);
      q.push({ny, nx});
    }
  }
  return max_dist - 1;
}

void solve() {
  int max_dist = 0;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (board[i][j] == 0) continue;
      max_dist = max(max_dist, bfs({i, j}));
    }
  }
  cout << max_dist;
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
보물섬 지도, 직사각형 모양
육지(L), 바다(W)
상하좌우 이동
한칸 이동 한시간
보물은 서로간의 거리 가장 먼 두 위치에 있다.
*/