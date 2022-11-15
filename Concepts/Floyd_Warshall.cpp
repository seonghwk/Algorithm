#include <iostream>
#include <vector>
//#include <string.h>

using namespace std;

// 정점의 개수
int V;

// 그래프의 인접 행렬 표현
// adj[u][v] : u에서 v로 가는 간선의 가중치. 간선이 없으면 아주 큰 값을 넣는다.
vector<vector<int>> adj;  // int adj[MAX_V][MAX_V];

// via[u][v] : u에서 v까지 가는 최단 경로가 경유하는 점 중 가장 번호가 큰 정점
vector<vector<int>> via;  // int via[MAX_V][MAX_V];

// 플로이드의 모든 쌍 최단 거리 알고리즘
void floyd() {
  for (int i = 0; i < V; i++)
    adj[i][i] = 0;  // 자기 자신으로의 최단거리는 0이다.

  via = vector<vector<int>>(
      V, vector<int>(V, -1));  // memset(via, -1, sizeof(via));

  for (int k = 0; k < V; k++) {
    for (int i = 0; i < V; i++) {
      for (int j = 0; j < V; j++) {
        // 지금까지 구한 i, j 사이의 최단거리보다, k를 거치는 것이 짧으면 갱신
        if (adj[i][j] > adj[i][k] + adj[k][j]) {
          via[i][j] = k;
          adj[i][j] = adj[i][k] + adj[k][j];
        }
      }
    }
  }
}

// u에서 v로 가는 최단 경로를 계산해 path에 저장한다.
void reconstruct(int u, int v, vector<int>& path) {
  // 기저사례
  if (via[u][v] == -1) {  //  u에서 v로 가기 위해 거쳐야 할 곳이 없다.
    path.push_back(u);
    if (u != v)
      path.push_back(v);  // 자기 자신으로 가는 경우가 아니라면 도착한 곳을 기록
  } else {
    int w = via[u][v];  // u에서 v로 가기 위해 w를 거치는 것이 최단 경로
    reconstruct(u, w, path);  // u에서 w까지 가기 위한 경로를 만들어낸다.
    path.pop_back();  // w가 중복으로 들어가므로 지운다.
    reconstruct(w, v, path);  // w에서 v까지 가기 위한 경로를 만들어낸다.
  }
}
