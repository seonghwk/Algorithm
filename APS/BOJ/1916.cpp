#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
	int to;
	int cost;
};

struct cmp {
	bool operator()(Edge a, Edge b) {
		if (a.cost < b.cost)
			return false;
		if (a.cost > b.cost)
			return true;
		return false;
	}
};

int N, M;
int A, B;
vector<Edge> v[1001];
int dist[1001];
priority_queue<Edge, vector<Edge>, cmp> pq;

void dijkstra() {
	for (int i = 1; i <= N; i++)
		dist[i] = 2147483647;
	dist[A] = 0;
	pq.push({ A, 0 });

	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();

		if (dist[now.to] < now.cost)
			continue;
		for (int i = 0; i < v[now.to].size(); i++) {
			Edge next = v[now.to][i];
			if (dist[next.to] <= now.cost + next.cost)
				continue;
			dist[next.to] = now.cost + next.cost;
			pq.push({ next.to, dist[next.to] });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back({ to, cost });
	}
	cin >> A >> B;
	dijkstra();
	cout << dist[B];
	return 0;
}