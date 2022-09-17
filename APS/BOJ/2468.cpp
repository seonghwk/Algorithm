#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

struct Node {
	int y;
	int x;
};

int board[100][100];
int visited[100][100];
int N;
int height_max;
int safe_zone_cnt;
int safe_zone_max;
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

bool inRange(int y, int x) {
	if (0 <= y && y < N && 0 <= x && x < N)
		return true;
	return false;
}

void bfs(Node start, int height) {
	queue<Node> q;
	q.push(start);
	visited[start.y][start.x] = 1;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			if (!inRange(ny, nx))
				continue;
			if (board[ny][nx] <= height)
				continue;
			if (visited[ny][nx] != 0)
				continue;
			visited[ny][nx] = 1;
			q.push({ ny, nx });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			height_max = max(height_max, board[i][j]);
		}
	}

	for (int height = 0; height <= height_max; height++) {
		memset(visited, 0, sizeof(visited));
		safe_zone_cnt = 0;
		for (int row = 0; row < N; row++) {
			for (int col = 0; col < N; col++) {
				if (board[row][col] <= height)
					continue;
				if (visited[row][col] != 0)
					continue;
				safe_zone_cnt++;
				bfs({ row, col }, height);
			}
		}
		safe_zone_max = max(safe_zone_max, safe_zone_cnt);
	}

	cout << safe_zone_max;

	return 0;
}