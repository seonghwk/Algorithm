#include <limits.h>

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, E;
int v1, v2;
vector<vector<int>> adj_mat;

void input() {
  cin >> N >> E;
  adj_mat = vector<vector<int>>(N + 1, vector<int>(N + 1, INT_MAX / 2));
  int a, b, c;
  for (int i = 0; i < E; i++) {
    cin >> a >> b >> c;
    adj_mat[a][b] = c;
    adj_mat[b][a] = c;
  }
  cin >> v1 >> v2;
}

void floyd() {
  for (int i = 1; i <= N; i++) adj_mat[i][i] = 0;
  for (int k = 1; k <= N; k++) {
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        adj_mat[i][j] = min(adj_mat[i][j], adj_mat[i][k] + adj_mat[k][j]);
      }
    }
  }
}

void solve1() {
  floyd();
  int dist_list[][3] = {{adj_mat[1][v1], adj_mat[v1][v2], adj_mat[v2][N]},
                        {adj_mat[1][v2], adj_mat[v2][v1], adj_mat[v1][N]}};
  int dist_sum[2] = {};
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      if (dist_list[i][j] == INT_MAX / 2) {
        dist_sum[i] = INT_MAX;
        break;
      }
      dist_sum[i] += dist_list[i][j];
    }
  }
  int ret = min(dist_sum[0], dist_sum[1]);
  if (ret == INT_MAX) ret = -1;
  cout << ret;
}

struct Edge {
  int to, cost;
};

bool operator<(Edge a, Edge b) {
  if (a.cost < b.cost) return true;
  if (a.cost > b.cost) return false;
  return false;
}

vector<vector<Edge>> adj_lst;

void input2() {
  cin >> N >> E;
  adj_lst = vector<vector<Edge>>(N + 1);
  int a, b, c;
  for (int i = 0; i < E; i++) {
    cin >> a >> b >> c;
    adj_lst[a].push_back({b, c});
    adj_lst[b].push_back({a, c});
  }
  cin >> v1 >> v2;
}

vector<int> dijkstra(Edge start) {
  priority_queue<Edge> pq;
  vector<int> dist(N + 1, INT_MAX);
  pq.push(start);
  dist[start.to] = start.cost;

  while (!pq.empty()) {
    Edge now = pq.top();
    pq.pop();

    if (dist[now.to] < now.cost) continue;

    for (int i = 0; i < adj_lst[now.to].size(); i++) {
      Edge next = adj_lst[now.to][i];
      if (dist[next.to] <= dist[now.to] + next.cost) continue;
      dist[next.to] = dist[now.to] + next.cost;
      pq.push({next.to, dist[next.to]});
    }
  }
  return dist;
}

void solve2() {
  vector<int> dist_from_origin = dijkstra({1, 0});
  vector<int> dist_from_v1 = dijkstra({v1, 0});
  vector<int> dist_from_v2 = dijkstra({v2, 0});

  int dist_list[][3] = {
      {dist_from_origin[v1], dist_from_v1[v2], dist_from_v2[N]},
      {dist_from_origin[v2], dist_from_v2[v1], dist_from_v1[N]}};
  int dist_sum[2] = {};
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      if (dist_list[i][j] == INT_MAX) {
        dist_sum[i] = INT_MAX;
        break;
      }
      dist_sum[i] += dist_list[i][j];
    }
  }
  int ret = min(dist_sum[0], dist_sum[1]);
  if (ret == INT_MAX) ret = -1;
  cout << ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // input1();
  // solve1();
  input2();
  solve2();

  return 0;
}

/*
무향그래프
1번에서 N번으로 최단거리 이동
두 정점은 반드시 통과
방문한 정점, 간선 다시 이동 가능하다

그래프 표현 : 인접 행렬
1 -> v1 -> v2 -> N
*/