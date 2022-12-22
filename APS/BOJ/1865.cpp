#include <iostream>
#include <vector>

#define MAX_DIST 10000

using namespace std;

int N, M, W;  // N: 지점의 수, M: 도로의 개수, W: 웜홀의 개수
vector<vector<pair<int, int>>> adj;  // 인접 리스트

void input() {
  cin >> N >> M >> W;
  adj = vector<vector<pair<int, int>>>(N + 1);  // 1-indexing 사용
  int S, E, T;
  for (int i = 0; i < M; i++) {
    cin >> S >> E >> T;  // S, E: 연결된 지점, T: 걸리는 시간
    adj[S].push_back({E, T});
    adj[E].push_back({S, T});
  }
  for (int i = 0; i < W; i++) {
    cin >> S >> E >> T;  // S: 시작 지점, E: 도착 지점, T: 줄어드는 시간
    adj[S].push_back({E, -T});
  }
}

vector<int> bellmanFord(int src) {
  vector<int> upper(N + 1, MAX_DIST);
  upper[src] = 0;
  bool updated;

  for (int iter = 0; iter < N; iter++) {
    updated = false;
    for (int here = 1; here <= N; here++) {
      for (int i = 0; i < adj[here].size(); i++) {
        int there = adj[here][i].first;
        int cost = adj[here][i].second;
        if (upper[there] > upper[here] + cost) {
          upper[there] = upper[here] + cost;
          updated = true;
        }
      }
    }
    if (upper[src] < 0) break;
    if (!updated) break;
  }
  return upper;
}

void solve() {
  vector<int> dist;
  for (int src = 1; src <= N; src++) {
    dist = bellmanFord(src);
    if (dist[src] < 0) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int TC;
  cin >> TC;
  for (int i = 0; i < TC; i++) {
    input();
    solve();
  }

  return 0;
}