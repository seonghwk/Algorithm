#include <iostream>

using namespace std;

int A[8];
int N;
int arr[8];
int visited[8];
int diff_max = -2147483648;

void calcDiff() {
	int diff = 0;
	for (int i = 1; i < N; i++) {
		diff += abs(arr[i] - arr[i - 1]);
	}
	diff_max = max(diff_max, diff);
}

void dfs(int level) {
	// base case
	if (level == N) {
		calcDiff();
		return;
	}
	// recursive case
	for (int i = 0; i < N; i++) {
		if (visited[i] != 0)
			continue;
		visited[i] = 1;
		arr[level] = A[i];
		dfs(level + 1);
		visited[i] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	dfs(0);
	cout << diff_max;
	return 0;
}