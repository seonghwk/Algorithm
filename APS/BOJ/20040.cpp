#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> parent;
vector<pair<int, int>> link;

int Find(int now) {
  if (parent[now] == now) return now;
  return parent[now] = Find(parent[now]);
}

void Union(int a, int b) {
  int pa = Find(a);
  int pb = Find(b);

  parent[pb] = pa;
}

void input() {
  cin >> N >> M;
  parent.resize(N);
  link.resize(M);
  for (int i = 0; i < N; i++) parent[i] = i;
  for (int i = 0; i < M; i++) {
    cin >> link[i].first >> link[i].second;
  }
}

void solve() {
  for (int i = 0; i < M; i++) {
    int pa = Find(link[i].first);
    int pb = Find(link[i].second);
    if (pa == pb) {
      cout << i + 1;
      return;
    }
    Union(pa, pb);
  }
  cout << 0;
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
사이클 완성하면 게임 종료
사이클 완성된 차례의 번호,
안끝났으면 0
*/