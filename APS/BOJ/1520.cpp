#include <iostream>
#include <string.h>

using namespace std;

int N, M;
int board[500][500];

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

int dp[500][500];

int dfs(int y, int x) {
	if (y == 3 && x == 3)
		int de = -1;
	// base case
	if (y == N - 1 && x == M - 1)
		return 1;
	if (dp[y][x] != -1)
		return dp[y][x];
	// recursive case
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (!(0 <= ny && ny < N && 0 <= nx && nx < M))
			continue;
		if (board[y][x] <= board[ny][nx])
			continue;
		cnt += dfs(ny, nx);
	}
	dp[y][x] = cnt;
	return dp[y][x];
}

int main() {

	memset(dp, -1, sizeof(dp));

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
	cout << dfs(0, 0);

	return 0;
}