#include <limits.h>

#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> adj;

void input() {
  cin >> N >> M;
  adj = vector<vector<int>>(N + 1, vector<int>(N + 1, INT_MAX / 2));
  int A, B;
  for (int i = 0; i < M; i++) {
    cin >> A >> B;
    adj[A][B] = 1;
    adj[B][A] = 1;
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
  int min_dist = INT_MAX;
  vector<int> result(2);
  for (int i = 1; i <= N; i++) {
    for (int j = i + 1; j <= N; j++) {
      int dist = 0;
      for (int k = 1; k <= N; k++) {
        dist += min(adj[k][i], adj[k][j]);
      }
      if (min_dist > dist) {
        min_dist = dist;
        result[0] = i;
        result[1] = j;
      }
    }
  }
  cout << result[0] << " " << result[1] << " " << min_dist * 2;
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
N개의 건물, M개의 도로, 1-indexing
도로는 1시간 소요 (양방향))
건물 2개를 골라서 치킨집으로
모든 건물에서의 접근성 합을 최소화
건물X의 접근성 : X에서 가장 가까운 치킨집 왕복 시간
최단 시간의 총합

*/