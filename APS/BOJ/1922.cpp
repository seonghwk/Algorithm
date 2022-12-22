#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Edge {
  int from, to, cost;
};

bool operator<(Edge a, Edge b) { return a.cost > b.cost; }

int N, M;
priority_queue<Edge> pq;
vector<int> parent;

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
  int a, b, c;
  parent.resize(N + 1);
  for (int i = 1; i <= N; i++) parent[i] = i;
  for (int i = 0; i < M; i++) {
    cin >> a >> b >> c;
    if (a == b) continue;
    pq.push({a, b, c});
  }
}

int mst() {
  int cost = 0;
  while (!pq.empty()) {
    Edge now = pq.top();
    pq.pop();

    if (Find(now.from) == Find(now.to)) continue;
    Union(now.from, now.to);
    cost += now.cost;
  }
  return cost;
}

void solve() { cout << mst(); }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}

/*
모든 컴퓨터 연결
연결 비용 최소로
*/