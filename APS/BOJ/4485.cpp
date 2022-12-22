#include <limits.h>

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int y, x;
};

struct Edge {
  Node to;
  int cost;
};

bool operator<(Edge a, Edge b) {
  if (a.cost < b.cost) return false;
  if (a.cost > b.cost) return true;
  return false;
}

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};

int N;
int tc;
vector<vector<int>> board;
vector<vector<int>> dist;

void input() {
  cin >> N;
  board = vector<vector<int>>(N, vector<int>(N));
  dist = vector<vector<int>>(N, vector<int>(N, INT_MAX));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
    }
  }
}

void dijkstra() {
  priority_queue<Edge> pq;
  pq.push({{0, 0}, board[0][0]});
  dist[0][0] = board[0][0];

  while (!pq.empty()) {
    Edge now = pq.top();
    pq.pop();

    if (dist[now.to.y][now.to.x] < now.cost) continue;

    for (int dir = 0; dir < 4; dir++) {
      int ny = now.to.y + dy[dir];
      int nx = now.to.x + dx[dir];
      if (!(0 <= ny && ny < N) || !(0 <= nx && nx < N)) continue;
      if (dist[ny][nx] <= dist[now.to.y][now.to.x] + board[ny][nx]) continue;
      dist[ny][nx] = dist[now.to.y][now.to.x] + board[ny][nx];
      pq.push({{ny, nx}, dist[ny][nx]});
    }
  }
}

void solve() {
  dijkstra();
  cout << "Problem " << tc << ": " << dist[N - 1][N - 1] << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  tc = 1;
  while (true) {
    input();
    if (N == 0) break;
    solve();
    tc++;
  }

  return 0;
}

/*
젤다의 전설 화폐단위 루피
검정색 루피

N*N 크기 동굴의 (0,0)에서 시작
각 칸마다 도둑루피가 있다.
최소 금액을 잃어서 (N-1, N-1)까지 이동해야한다.
*/