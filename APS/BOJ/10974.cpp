#include <iostream>

using namespace std;

int N;
int path[8];
int visited[9];

void dfs(int level) {
	// base case
	if (level == N) {
		for (int i = 0; i < N; i++) {
			cout << path[i] << " ";
		}
		cout << "\n";
		return;
	}

	// recursive case
	for (int i = 1; i <= N; i++) {
		if (visited[i] != 0)
			continue;
		visited[i] = 1;
		path[level] = i;
		dfs(level + 1);
		visited[i] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	dfs(0);


	return 0;
}