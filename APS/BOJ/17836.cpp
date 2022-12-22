#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int y, x;
};

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};

int N, M, T;
vector<vector<int>> board;
vector<vector<int>> visited;
Node gram;

void input() {
  cin >> N >> M >> T;
  board = vector<vector<int>>(N, vector<int>(M, 0));
  visited = vector<vector<int>>(N, vector<int>(M, 0));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
      if (board[i][j] == 2) gram = {i, j};
    }
  }
}

void bfs() {
  queue<Node> q;
  visited[0][0] = 1;
  q.push({0, 0});

  while (!q.empty()) {
    Node now = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = now.y + dy[i];
      int nx = now.x + dx[i];
      if (!(0 <= ny && ny < N) || !(0 <= nx && nx < M)) continue;
      if (board[ny][nx] == 1) continue;
      if (visited[ny][nx] != 0) continue;
      visited[ny][nx] = visited[now.y][now.x] + 1;
      q.push({ny, nx});
    }
  }
}

void solve() {
  bfs();
  int dist_direct = visited[N - 1][M - 1];
  int dist_gram = visited[gram.y][gram.x];
  int dist_detour = dist_gram + abs(N - 1 - gram.y) + abs(M - 1 - gram.x);
  int dist_min;
  if (dist_direct == 0) {
    if (dist_gram == 0) {
      cout << "Fail";
      return;
    }
    dist_min = dist_detour;
  } else {
    dist_min = min(dist_direct, dist_detour);
  }

  if (dist_min <= T + 1) {
    cout << dist_min - 1;
  } else {
    cout << "Fail";
  }
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
N-by-M board, 1-indexing
벽 피해서 공주 위치로
T 시간 이내에 도달해야한다.
상하좌우 이동
'그람' 구한 뒤에는 벽 부술 수 있다.
얼마나 빨리 구할 수 있는가?

구할 수 없으면 "Fail"

1. 그냥 가기
2. 그람 찾기, 그람부터 공주 찾기


1. 그람 찾기도 전에 못가는 경우 -> fail
2. 못갔는데 그람은 찾았다 -> 도착 가능하다, 시간 확인
3. 그람도 찾고 도착도 하고 -> 가능, 시간 확인
*/
