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
  int A, B, C;
  parent.resize(N + 1);
  for (int i = 1; i <= N; i++) parent[i] = i;
  for (int i = 0; i < M; i++) {
    cin >> A >> B >> C;
    pq.push({A, B, C});
  }
}

int mst() {
  int cost = 0;
  while (N > 2) {
    Edge now = pq.top();
    pq.pop();

    if (Find(now.from) == Find(now.to)) continue;
    Union(now.from, now.to);
    cost += now.cost;
    N--;
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
원숭이 탈출
N개의 집, M개의 길, 양방향
유지비가 있다.

두 개의 분리된 마을로 분할
분리된 마을 안에 집들이 서로 연결되도록
임의의 두 집 사이에 경로 항상 존재 해야함
마을에는 집이 하나 이상 있어야 함

길의 유지비 합을 최소로 할때의 유지비
*/