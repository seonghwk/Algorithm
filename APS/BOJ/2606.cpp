#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> v[101];

int bfs(int start) {
	int visited[101] = {};
	queue<int> q;
	int cnt = 0;
	
	visited[start] = 1;
	q.push(start);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			if (visited[next] != 0)
				continue;
			visited[next] = 1;
			q.push(next);
			cnt++;
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cntNode, cntEdge;

	cin >> cntNode;
	cin >> cntEdge;
	for (int i = 0; i < cntEdge; i++) {
		int from, to;
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}

	cout << bfs(1);
	
	return 0;
}