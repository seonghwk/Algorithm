#include <limits.h>

#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> adj;
vector<vector<int>> via;
vector<int> bully;
vector<pair<int, int>> query;

int N, M, Q;

void input() {
  cin >> N >> M >> Q;
  adj = vector<vector<int>>(N + 1, vector<int>(N + 1, INT_MAX / 4));
  bully = vector<int>(N + 1);
  for (int i = 1; i <= N; i++) cin >> bully[i];
  int a, b, d;
  for (int i = 0; i < M; i++) {
    cin >> a >> b >> d;
    adj[a][b] = d;
    adj[b][a] = d;
  }
  query = vector<pair<int, int>>(Q);
  for (int i = 0; i < Q; i++) {
    cin >> query[i].first >> query[i].second;
  }
}

void floyd() {
  for (int i = 1; i <= N; i++) adj[i][i] = 0;

  for (int k = 1; k <= N; k++) {
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
      }
    }
  }
}

void solve() {
  floyd();

  int S, T, add_cost, min_dist;
  for (int i = 0; i < Q; i++) {
    S = query[i].first;
    T = query[i].second;
    if (adj[S][T] == INT_MAX / 4) {
      cout << "-1\n";
      continue;
    }
    min_dist = INT_MAX;
    add_cost = max(bully[S], bully[T]);
    for (int k = 1; k <= N; k++) {
      if (adj[S][k] == INT_MAX / 4 || adj[k][T] == INT_MAX / 4) continue;
      if (adj[S][k] == 0 || adj[k][T] == 0) continue;
      min_dist = min(min_dist, adj[S][k] + max(add_cost, bully[k]) + adj[k][T]);
    }
    cout << min_dist << "\n";
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
동물원 탈출한 원숭이의 세상구경
추격전
양방향 그래프
원숭이는 시작도시에서 도착도시까지 최대한 빠르게
멍멍이는 원숭이 도망 경로중에서 대기중
가장 오랜시간 괴롭힐 수 있는 도시에서 대기중
피할수는 없다.

k를 경유할 때
괴롭힌 시간 포함해서 최소 시간 소요해야한다.
괴롭힌 시간은 경로상 최대값이어야한다.
*/