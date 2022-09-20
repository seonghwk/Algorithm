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

int V, E;
int K;
vector<Edge> v[20001];
priority_queue<Edge, vector<Edge>, cmp> pq;
int dist[20001];

void dijkstra() {
	for (int i = 1; i <= V; i++) {
		dist[i] = 2147483647;
	}
	dist[K] = 0;

	pq.push({ K, 0 });

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

	cin >> V >> E;
	cin >> K;
	for (int i = 0; i < E; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back({ to, cost });
	}
	dijkstra();
	for (int i = 1; i <= V; i++) {
		if (dist[i] == 2147483647)
			cout << "INF";
		else
			cout << dist[i];
		cout << "\n";
	}
	return 0;
}