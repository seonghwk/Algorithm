#include <iostream>

using namespace std;

int N;
int W[10][10];
int visited[10];
int cost_min = 2147483647;

void dfs(int level, int now, int cost, int goal) {
	// base case
	if (level == N) {
		if (W[now][goal] == 0)
			return;
		cost_min = min(cost_min, cost + W[now][goal]);
		return;
	}
	// recursive case
	for (int i = 0; i < N; i++) {
		if (visited[i] != 0)
			continue;
		if (W[now][i] == 0)
			continue;
		visited[i] = 1;
		dfs(level + 1, i, cost + W[now][i], goal);
		visited[i] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> W[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		visited[i] = 1;
		dfs(1, i, 0, i);
		visited[i] = 0;
	}

	cout << cost_min;

	return 0;
}