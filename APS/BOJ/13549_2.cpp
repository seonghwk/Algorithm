#include <iostream>
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

int N, K;
int dist[100001];

bool inRange(int pos) {
	if (0 <= pos && pos <= 100000)
		return true;
	return false;
}

void dijkstra(int from, int to) {
	for (int i = 0; i < 100001; i++)
		dist[i] = 2147483647;
	dist[from] = 0;
	priority_queue<Edge, vector<Edge>, cmp> pq;
	pq.push({ from, 0 });

	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();

		if (dist[now.to] < now.cost)
			continue;

		if (now.to == to) {
			cout << dist[to];
			break;
		}

		if (inRange(now.to - 1)) {
			if (dist[now.to - 1] > now.cost + 1) {
				dist[now.to - 1] = now.cost + 1;
				pq.push({ now.to - 1, dist[now.to - 1] });
			}
		}
		if (inRange(now.to + 1)) {
			if (dist[now.to + 1] > now.cost + 1) {
				dist[now.to + 1] = now.cost + 1;
				pq.push({ now.to + 1, dist[now.to + 1] });
			}
		}
		if (inRange(now.to * 2)) {
			if (dist[now.to * 2] > now.cost) {
				dist[now.to * 2] = now.cost;
				pq.push({ now.to * 2, dist[now.to *2] });
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	dijkstra(N, K);

	return 0;
}