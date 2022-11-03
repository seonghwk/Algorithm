#include <iostream>

using namespace std;

int N;
int board[16][16];
int visited[16];
int diff_min;

int find_diff() {
	int A = 0;
	int B = 0;
	for (int i = 0; i < N; i++) {
		if (visited[i] == 1) {
			for (int j = 0; j < N; j++) {
				if (visited[j] != 1)
					continue;
				A += board[i][j];
			}
		}
		else if (visited[i] == 0) {
			for (int j = 0; j < N; j++) {
				if (visited[j] != 0)
					continue;
				B += board[i][j];
			}
		}
	}
	return abs(A - B);
}

void dfs(int level, int num) {
	// base case
	if (level == N / 2) {
		diff_min = min(diff_min, find_diff());
		return;
	}
	// recursive case
	for (int i = num; i < N; i++) {
		visited[i] = 1;
		dfs(level + 1, i + 1);
		visited[i] = 0;
	}
}

int solution() {
	dfs(0, 0);
	return diff_min;
}

void input() {
	diff_min = 2147483647;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
}

int main() {

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		input();
		cout << "#" << tc << " " << solution() << "\n";
	}

	return 0;
}