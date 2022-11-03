#include <iostream>

using namespace std;

int N, X;
int board[20][20];

int solution() {
	int cnt = 0;
	for (int row = 0; row < N; row++) {
		int prev = board[row][0];
		int length = 1;
		int used[20] = {};
		int flag = 0;
		for (int col = 1; col < N; col++) {
			int now = board[row][col];
			if (prev == now) {
				length++;
				continue;
			}
			if (abs(prev - now) > 1) {
				flag = 1;
				break;
			}
			if (prev < now) {
				if (length < X) {
					flag = 1;
					break;
				}
				for (int i = col - 1; i > col - 1 - X; i--) {
					if (used[i] == 1){
						flag = 1;
						break;
					}
				}
				if (flag == 1)
					break;
				for (int i = col - 1; i > col - 1 - X; i--) {
					used[i] = 1;
				}
			}
			prev = now;
			length = 1;
		}
		prev = board[row][N - 1];
		length = 1;
		for (int col = N - 2; col >= 0; col--) {
			int now = board[row][col];
			if (prev == now) {
				length++;
				continue;
			}
			if (abs(prev - now) > 1) {
				flag = 1;
				break;
			}
			if (prev < now) {
				if (length < X) {
					flag = 1;
					break;
				}
				for (int i = col + 1; i < col + 1 + X; i++) {
					if (used[i] == 1) {
						flag = 1;
						break;
					}
				}
				if (flag == 1)
					break;
				for (int i = col + 1; i < col + 1 + X; i++) {
					used[i] = 1;
				}
			}
			prev = now;
			length = 1;
		}
		if (flag == 0)
			cnt++;
	}
	for (int col = 0; col < N; col++) {
		int prev = board[0][col];
		int length = 1;
		int used[20] = {};
		int flag = 0;
		for (int row = 1; row < N; row++) {
			int now = board[row][col];
			if (prev == now) {
				length++;
				continue;
			}
			if (abs(prev - now) > 1) {
				flag = 1;
				break;
			}
			if (prev < now) {
				if (length < X) {
					flag = 1;
					break;
				}
				for (int i = row - 1; i > row - 1 - X; i--) {
					if (used[i] == 1) {
						flag = 1;
						break;
					}
				}
				if (flag == 1)
					break;
				for (int i = row - 1; i > row - 1 - X; i--) {
					used[i] = 1;
				}
			}
			prev = now;
			length = 1;
		}
		prev = board[N - 1][col];
		length = 1;
		for (int row = N - 2; row >= 0; row--) {
			int now = board[row][col];
			if (prev == now) {
				length++;
				continue;
			}
			if (abs(prev - now) > 1) {
				flag = 1;
				break;
			}
			if (prev < now) {
				if (length < X) {
					flag = 1;
					break;
				}
				for (int i = row + 1; i < row + 1 + X; i++) {
					if (used[i] == 1) {
						flag = 1;
						break;
					}
				}
				if (flag == 1)
					break;
				for (int i = row + 1; i < row + 1 + X; i++) {
					used[i] = 1;
				}
			}
			prev = now;
			length = 1;
		}
		if (flag == 0)
			cnt++;

	}
	return cnt;
}

void input() {
	cin >> N >> X;
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