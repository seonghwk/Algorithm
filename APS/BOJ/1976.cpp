#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> adj;
vector<int> path;

vector<int> parent;

int Find(int now) {
  if (parent[now] == now) return now;
  parent[now] = Find(parent[now]);
  return parent[now];
}

void Union(int a, int b) {
  int pa = Find(a);
  int pb = Find(b);

  parent[pb] = pa;
}

void input2() {
  cin >> N >> M;
  parent.resize(N + 1);
  for (int i = 1; i <= N; i++) parent[i] = i;
  int connected;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> connected;
      if (connected == 1) Union(i, j);
    }
  }
  path.resize(M);
  for (int i = 0; i < M; i++) {
    cin >> path[i];
  }
}

void solve2() {
  for (int i = 0; i < M - 1; i++) {
    if (Find(path[i]) != Find(path[i + 1])) {
      cout << "NO";
      return;
    }
  }
  cout << "YES";
}

void input() {
  cin >> N >> M;
  adj.resize(N + 1, vector<int>(N + 1));
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> adj[i][j];
    }
  }
  path.resize(M);
  for (int i = 0; i < M; i++) {
    cin >> path[i];
  }
}

void floyd() {
  for (int i = 1; i <= N; i++) adj[i][i] = 1;
  for (int k = 1; k <= N; k++) {
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        adj[i][j] = adj[i][j] || (adj[i][k] && adj[k][j]);
      }
    }
  }
}

void solve() {
  floyd();
  for (int i = 0; i < M - 1; i++) {
    if (adj[path[i]][path[i + 1]] != 1) {
      cout << "NO";
      return;
    }
  }
  cout << "YES";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // input();
  // solve();

  input2();
  solve2();

  return 0;
}

/*
N개의 도시
여행 경로 가능한지
*/