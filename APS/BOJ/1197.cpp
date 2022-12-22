#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;

struct Edge {
  int from, to, cost;
};

bool operator<(Edge a, Edge b) {
  if (a.cost < b.cost) return true;
  if (a.cost > b.cost) return false;
  return false;
}

int V, E;
vector<int> parent;
vector<Edge> edge;

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
  cin >> V >> E;
  parent = vector<int>(V + 1);
  iota(parent.begin(), parent.end(), 0);
  int A, B, C;
  for (int i = 0; i < E; i++) {
    cin >> A >> B >> C;
    edge.push_back({A, B, C});
  }
}

int mst() {
  int cost = 0;
  for (int i = 0; i < edge.size(); i++) {
    int from = edge[i].from;
    int to = edge[i].to;
    if (Find(from) == Find(to)) continue;
    Union(from, to);
    cost += edge[i].cost;
  }
  return cost;
}

void solve() {
  sort(edge.begin(), edge.end());
  cout << mst();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}