#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int N, M, V;
int arr[1001][1001];
int visited[1001];

void dfs(int now) {
	cout << now << " ";
	// base case

	// recursive case
	for (int i = 1; i <= N; i++) {
		if (arr[now][i] == 0)
			continue;
		if (visited[i] != 0)
			continue;
		visited[i] = 1;
		dfs(i);
	}

}

void bfs(int start) {
	queue<int> q;
	q.push(start);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		cout << now << " ";

		for (int i = 1; i <= N; i++) {
			if (arr[now][i] == 0)
				continue;
			if (visited[i] != 0)
				continue;
			visited[i] = 1;
			q.push(i);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		arr[from][to] = 1;
		arr[to][from] = 1;
	}

	visited[V] = 1;
	dfs(V);
	cout << "\n";
	memset(visited, 0, sizeof(visited));

	visited[V] = 1;
	bfs(V);
	cout << "\n";

	return 0;
}
