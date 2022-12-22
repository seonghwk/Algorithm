#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Node {
  int y, x;
};

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};

int N, K;
int S, X, Y;

vector<vector<int>> board;
vector<Node> virus_init;

bool operator<(Node a, Node b) { return (board[a.y][a.x] < board[b.y][b.x]); }

void input() {
  cin >> N >> K;
  board = vector<vector<int>>(N + 1, vector<int>(N + 1));
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> board[i][j];
      if (board[i][j] != 0) virus_init.push_back({i, j});
    }
  }
  cin >> S >> X >> Y;
}

vector<Node> bfs(vector<Node>& v) {
  vector<Node> ret;
  for (int i = 0; i < v.size(); i++) {
    Node now = v[i];

    for (int dir = 0; dir < 4; dir++) {
      int ny = now.y + dy[dir];
      int nx = now.x + dx[dir];
      if (!(1 <= ny && ny <= N) || !(1 <= nx && nx <= N)) continue;
      if (board[ny][nx] != 0) continue;
      board[ny][nx] = board[now.y][now.x];
      ret.push_back({ny, nx});
    }
  }
  return ret;
}

void solve() {
  vector<Node> virus(virus_init);
  for (int i = 0; i < S; i++) {
    sort(virus.begin(), virus.end());
    virus = bfs(virus);
  }
  cout << board[X][Y];
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
N-by-N board, 1-indexing
바이러스 종류 : 1 ~ K
1초마다 상하좌우 증식
번호 낮은 바이러스부터 증식
이미 바이러스 존재하는 칸에 증싟 불가
S초 이후 (X,Y)에 존재하는 바이러스 종류

*/