#include <iostream>
#include <string.h>

using namespace std;

struct Node {
	int y;
	int x;
};

int N;
int board[20][20];
Node start;
int DAT[101];
int max_cnt;

const int dy[] = { 1, 1, -1, -1 };
const int dx[] = { 1, -1, -1, 1 };

void dfs(Node now, int dir, int cnt) {
	// base case
	if (now.y == start.y && now.x == start.x && dir == 3) {
		max_cnt = max(cnt, max_cnt);
		return;
	}

	// recursive case
	// 1. 방향 유지 2. 방향 꺾기
	for (int i = 0; i < 2; i++) {
		if (dir + i >= 4)
			continue;
		int ny = now.y + dy[dir + i];
		int nx = now.x + dx[dir + i];
		if (!(0 <= ny && ny < N && 0 <= nx && nx < N))
			continue;
		if (DAT[board[ny][nx]] != 0)
			continue;
		DAT[board[ny][nx]] = 1;
		dfs({ ny, nx }, dir + i, cnt + 1);
		DAT[board[ny][nx]] = 0;
	}
}

void solution() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			start = { i, j };
			dfs(start, 0, 0);
		}
	}
	if (max_cnt == 0)
		max_cnt = -1;
}

void input() {
	max_cnt = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			memset(DAT, 0, sizeof(DAT));
			cin >> board[i][j];
		}
	}


}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		input();
		solution();
		cout << "#" << tc << " " << max_cnt <<"\n";
	}

	return 0;
}

/*
dfs 구성
level : 끝까지
branch : 방향 유지, 방향 전환

가지치기
	1. 범위 벗어나는 위치
	2. 방문한적 있는 숫자

*/