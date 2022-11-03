#include <iostream>

using namespace std;

int N, M, C;
int board[10][10];

int dfs(int y, int x, int level, int honey, int cnt) {
	// base case
	if (level == M) {
		return honey;
	}
	// recursive case
	int ret = 0;
	ret = max(ret, dfs(y, x + 1, level + 1, honey, cnt));
	if (cnt + board[y][x] <= C)
		ret = max(ret, dfs(y, x + 1, level + 1, honey + board[y][x] * board[y][x], cnt + board[y][x]));
	return ret;
}

int solution() {
	int ret = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= N - M; j++) {
			// {i, j}에서 M개 뽑을 예정
			int a = dfs(i, j, 0, 0, 0);
			for (int ii = i; ii < N; ii++) {
				if (ii == i){
					for (int jj = j + M; jj <= N - M; jj++) {
						// {ii, jj}에서 뽑을 예정
						int b = dfs(ii, jj, 0, 0, 0);
						ret = max(ret, a + b);
					}
				}
				else {
					for (int jj = 0; jj <= N - M; jj++) {
						// {ii, jj}에서 뽑을 예정
						int b = dfs(ii, jj, 0, 0, 0);
						ret = max(ret, a + b);
					}
				}
			}
		}
	}

	return ret;
}

void input() {
	cin >> N >> M >> C;
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