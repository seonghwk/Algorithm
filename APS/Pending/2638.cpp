#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int y, x;
};

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, -1};

int N, M;
vector<vector<int>> board;
queue<Node> q_cheese;

void input() {
  cin >> N >> M;
  board.resize(N, vector<int>(M));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
      if (board[i][j] == 1) q_cheese.push({i, j});
    }
  }
}

queue<Node> contact_air(queue<Node> q) {
  queue<Node> ret;

  int cnt;
  while (!q.empty()) {
    Node now = q.front();
    q.pop();

    cnt = 0;
    for (int dir = 0; dir < 4; dir++) {
      int ny = now.y + dy[dir];
      int nx = now.x + dx[dir];

      if (!(0 <= ny && ny < N) || !(0 <= nx && nx < M)) continue;
      if (board[ny][nx]) }
  }
}

void solve() { q_cheese = contact_air(q_cheese); }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}

/*
N * M board (5 <= N, M <= 100)
바깥 공기와 4변 중 2변 이상 접촉하면 한시간 뒤 녹는다.

*/