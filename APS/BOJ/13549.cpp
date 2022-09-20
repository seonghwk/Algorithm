#include <iostream>
#include <queue>

using namespace std;

struct Node {
	int pos;
	int time;
};

int N, K;

void bfs(int from, int to) {
	int dist[100001];
	for (int i = 0; i < 100001; i++)
		dist[i] = 2147483647;
	queue<Node> q;
	q.push({ from, 0 });

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		if (dist[now.pos] < now.time)
			continue;

		if (now.pos == to) {
			cout << now.time;
			break;
		}
		if ((0 <= now.pos - 1 && now.pos - 1 <= 100000) && dist[now.pos - 1] > now.time + 1) {
			dist[now.pos - 1] = now.time + 1;
			q.push({ now.pos - 1, dist[now.pos - 1]});
		}
		if ((0 <= now.pos + 1 && now.pos + 1 <= 100000) && dist[now.pos + 1] > now.time + 1) {
			dist[now.pos + 1] = now.time + 1;
			q.push({ now.pos + 1, dist[now.pos + 1]});
		}
		if ((0 <= now.pos * 2 && now.pos * 2 <= 100000) && dist[now.pos * 2] > now.time) {
			dist[now.pos *2] = now.time;
			q.push({ now.pos * 2, dist[now.pos * 2]});
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	bfs(N, K);


	return 0;
}