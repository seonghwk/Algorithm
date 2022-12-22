#include <iostream>
#include <queue>
#include <vector>
#define MAX_TIME 2147483647

using namespace std;

struct Node {
  int y, x;
};

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};

int R, C;
vector<vector<char>> board;
vector<Node> jihoon;
vector<Node> fire;
vector<vector<int>> result_jihoon;
vector<vector<int>> result_fire;
int min_time = MAX_TIME;

void input() {
  cin >> R >> C;
  board.resize(R, vector<char>(C));
  for (int i = 0; i < R; i++) {
    string row;
    cin >> row;
    for (int j = 0; j < C; j++) {
      board[i][j] = row[j];
      if (board[i][j] == 'J') jihoon.push_back({i, j});
      if (board[i][j] == 'F') fire.push_back({i, j});
    }
  }
}

vector<vector<int>> bfs(char mode) {
  vector<vector<int>> visited(R, vector<int>(C, MAX_TIME));
  queue<Node> q;
  vector<Node> start;
  if (mode == 'J') start = jihoon;
  if (mode == 'F') start = fire;
  for (int i = 0; i < start.size(); i++) {
    visited[start[i].y][start[i].x] = 1;
    q.push(start[i]);
  }

  while (!q.empty()) {
    Node now = q.front();
    q.pop();

    for (int dir = 0; dir < 4; dir++) {
      int ny = now.y + dy[dir];
      int nx = now.x + dx[dir];
      if (!(0 <= ny && ny < R) || !(0 <= nx && nx < C)) continue;
      if (board[ny][nx] == '#') continue;
      if (mode == 'J' && (visited[now.y][now.x] + 1 >= result_fire[ny][nx]))
        continue;
      if (visited[ny][nx] != MAX_TIME) continue;
      visited[ny][nx] = visited[now.y][now.x] + 1;
      q.push({ny, nx});
    }
  }
  return visited;
}

void solve() {
  result_fire = bfs('F');
  result_jihoon = bfs('J');

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (0 < i && i < R - 1 && 0 < j && j < C - 1) continue;
      if (result_jihoon[i][j] == MAX_TIME) continue;
      if (result_jihoon[i][j] >= result_fire[i][j]) continue;
      min_time = min(min_time, result_jihoon[i][j]);
    }
  }
  if (min_time == MAX_TIME)
    cout << "IMPOSSIBLE";
  else
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