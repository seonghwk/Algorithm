#include <iostream>

using namespace std;

int N, M;
int cards[100];
int visited[100];
int closest_sum;

void dfs(int level, int sum) {
	// base case
	if (sum > M)
		return;
	if (level == 3) {
		closest_sum = max(closest_sum, sum);
		return;
	}
	// recursive case
	for (int i = 0; i < N; i++) {
		if (visited[i] != 0)
			continue;
		visited[i] = 1;
		dfs(level + 1, sum + cards[i]);
		visited[i] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> cards[i];
	}
	dfs(0, 0);
	cout << closest_sum;

	return 0;
}
