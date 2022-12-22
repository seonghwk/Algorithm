#include <limits.h>

#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> adj;

void input() {
  cin >> N;
  adj = vector<vector<int>>(N, vector<int>(N));
  string row;
  for (int i = 0; i < N; i++) {
    cin >> row;
    for (int j = 0; j < N; j++) {
      if (row[j] == 'Y') {
        adj[i][j] = 1;
      } else {
        adj[i][j] = INT_MAX / 2;
      }
    }
  }
}

void floyd() {
  for (int i = 0; i < N; i++) adj[i][i] = 0;
  for (int k = 0; k < N; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
      }
    }
  }
}

void solve() {
  floyd();
  int max_cnt = 0;
  for (int i = 0; i < N; i++) {
    int cnt = 0;
    for (int j = 0; j < N; j++) {
      if (1 <= adj[i][j] && adj[i][j] <= 2) cnt++;
    }
    if (max_cnt < cnt) {
      max_cnt = cnt;
    }
  }
  cout << max_cnt;
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
가장 유명한 사람
사람의 2-친구
직접 친구 이거나, 한 사람을 건너 아는 친구
*/