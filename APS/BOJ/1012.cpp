#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

struct Node {
	int y;
	int x;
};

int M, N, K;
int board[50][50];
int visited[50][50];
int dy[] = {-1, 1, 0, 0};
int dx[] = { 0, 0, -1, 1 };

void bfs(Node start) {
	queue<Node> q;
	q.push(start);

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			if (!(0 <= ny && ny < N && 0 <= nx && nx < M))
				continue;
			if (board[ny][nx] == 0)
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

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		memset(board, 0, sizeof(board));
		memset(visited, 0, sizeof(visited));

		cin >> M >> N >> K;
		for (int i = 0; i < K; i++) {
			int X, Y;
			cin >> X >> Y;
			board[Y][X] = 1;
		}
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (board[i][j] == 0)
					continue;
				if (visited[i][j] != 0)
					continue;
				cnt++;
				visited[i][j] = 1;
				bfs({ i, j});
			}
		}
		cout << cnt << "\n";
	}

	return 0;
}

