#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

struct Node {
	int y;
	int x;
};

int w, h;
int board[50][50];
int visited[50][50];

int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

void bfs(Node start) {
	queue<Node> q;
	q.push(start);
	visited[start.y][start.x] = 1;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 8; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			if (!(0 <= ny && ny < h && 0 <= nx && nx < w))
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

	int cnt;
	while (true){
		cnt = 0;
		memset(visited, 0, sizeof(visited));

		cin >> w >> h;
		if (w == 0 && h == 0)
			break;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> board[i][j];
			}
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (board[i][j] == 0)
					continue;
				if (visited[i][j] != 0)
					continue;
				cnt++;
				bfs({ i, j });
			}
		}
		cout << cnt << "\n";
	}


	return 0;
}