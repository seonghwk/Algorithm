#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int y, x;
};

int N;
vector<vector<int>> board;
vector<vector<int>> visited;

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};

void input() {
  cin >> N;
  board = vector<vector<int>>(N, vector<int>(N));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
    }
  }
}

void fill_island(Node start, int id) {
  queue<Node> q;
  q.push(start);
  visited[start.y][start.x] = 1;
  board[start.y][start.x] = id;

  while (!q.empty()) {
    Node now = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = now.y + dy[i];
      int nx = now.x + dx[i];
      if (!(0 <= ny && ny < N) || !(0 <= nx && nx < N)) continue;
      if (board[ny][nx] == 0) continue;
      if (visited[ny][nx] != 0) continue;
      visited[ny][nx] = 1;
      board[ny][nx] = id;
      q.push({ny, nx});
    }
  }
}

void bfs(Node start) {
  queue<Node> q;
  q.push(start);
  visited[start.y][start.x] = 1;

  while (!q.empty()) {
    Node now = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = now.y + dy[i];
      int nx = now.x + dx[i];
      if (!(0 <= ny && ny < N) || !(0 <= nx && nx < N)) continue;
      if (visited[ny][nx] == 1) continue;
    }
  }
}

void solution() {
  int id = 0;
  visited = vector<vector<int>>(N, vector<int>(N));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (board[i][j] == 0) continue;
      if (visited[i][j] != 0) continue;
      id++;
      fill_island({i, j}, id);
    }
  }
  cout << "\n";
  visited = vector<vector<int>>(N, vector<int>(N));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      // cout << board[i][j] << " ";
      if (board[i][j] != 0) continue;
      if (visited[i][j] != 0) continue;
      bfs({i, j});
    }
    // cout << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solution();

  return 0;
}