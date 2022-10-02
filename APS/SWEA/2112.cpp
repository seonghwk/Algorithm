//#include <iostream>
//#include <string.h>
//
//using namespace std;
//
//int D, W, K;
//int board[13][20];
//int inject_A[20];
//int inject_B[20];
//int min_inject;
//
//int col_max_consecutive(int col) {
//	int cnt_A = 0;
//	int cnt_B = 0;
//	int max_consecutive = 0;
//	int prev = board[0][col];
//
//	for (int row = 0; row < D; row++) {
//		int now = board[row][col];
//		if (now == prev) {
//			if (now == 0) {
//				cnt_A++;
//				cnt_B = 0;
//			}
//			else {
//				cnt_B++;
//				cnt_A = 0;
//			}
//		}
//		else {
//			if (now == 0) {
//				cnt_A = 1;
//				cnt_B = 0;
//			}
//			else {
//				cnt_B = 1;
//				cnt_A = 0;
//			}
//		}
//		max_consecutive = max(max_consecutive, max(cnt_A, cnt_B));
//		prev = now;
//	}
//	return max_consecutive;
//}
//
//int row_max_consecutive(int row) {
//	int cnt_A = 0;
//	int cnt_B = 0;
//	int max_consecutive = 0;
//	int prev = board[row][0];
//
//	for (int col = 0; col < W; col++) {
//		int now = board[row][col];
//		if (now == prev) {
//			if (now == 0) {
//				cnt_A++;
//				cnt_B = 0;
//			}
//			else {
//				cnt_B++;
//				cnt_A = 0;
//			}
//		}
//		else {
//			if (now == 0) {
//				cnt_A = 1;
//				cnt_B = 0;
//			}
//			else {
//				cnt_B = 1;
//				cnt_A = 0;
//			}
//		}
//		max_consecutive = max(max_consecutive, max(cnt_A, cnt_B));
//		prev = now;
//	}
//	return max_consecutive;
//}
//
//void dfs(int col, int level, int cnt) {
//	// base case
//	if (col == W) {
//		int flag = 0;
//		for (int j = 0; j < W; j++) {
//			if (col_max_consecutive(j) < K) {
//				flag = 1;
//				break;
//			}
//		}
//		if (flag == 0) {
//			min_inject = min(min_inject, cnt);
//		}
//		return;
//	}
//	// recursive case
//	if (col_max_consecutive(col) < K) {
//		for (int i = level; i < D; i++) {
//			if (row_max_consecutive(i) == W) {
//				dfs(col + 1, level, cnt);
//				continue;
//			}
//			else {
//				int temp[20];
//				memcpy(temp, board[i], sizeof(temp));
//
//				memcpy(board[i], inject_A, sizeof(inject_A));
//				dfs(col + 1, i + 1, cnt + 1);
//
//				memcpy(board[i], inject_B, sizeof(inject_B));
//				dfs(col + 1, i + 1, cnt + 1);
//
//				memcpy(board[i], temp, sizeof(temp));
//			}
//		}
//	}
//	else {
//		dfs(col + 1, level, cnt);
//	}
//
//}
//
//
//int solution() {
//	min_inject = 2147483647;
//
//	for (int i = 0; i < W; i++) {
//		inject_A[i] = 0;
//		inject_B[i] = 1;
//	}
//	dfs(0, 0, 0);
//
//	return min_inject;
//}
//
//void input() {
//	cin >> D >> W >> K;
//	for (int i = 0; i < D; i++) {
//		for (int j = 0; j < W; j++) {
//			cin >> board[i][j];
//		}
//	}
//
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	int T;
//	cin >> T;
//	for (int tc = 1; tc <= T; tc++) {
//		input();
//		cout << "#" << tc << " " << solution() <<"\n";
//	}
//
//	return 0;
//}