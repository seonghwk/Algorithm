#include <iostream>
#include <queue>

using namespace std;

struct Node {
	int y;
	int x;
};

int N, M, R, C, L;
int board[50][50];
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

int connected[8][4] = {
	{0, 0, 0, 0},
	{1, 1, 1, 1},
	{1, 1, 0, 0},
	{0, 0, 1, 1},
	{1, 0, 0, 1},
	{0, 1, 0, 1},
	{0, 1, 1, 0},
	{1, 0, 1, 0},
};

int flip_dir(int dir) {
	if (dir == 0)
		return 1;
	if (dir == 1)
		return 0;
	if (dir == 2)
		return 3;
	if (dir == 3)
		return 2;
}

bool isConnected(Node now, Node next, int dir) {
	int type_now = board[now.y][now.x];
	int type_next = board[next.y][next.x];
	if (connected[type_now][dir] == 0)
		return false;
	if (connected[type_next][flip_dir(dir)] == 0)
		return false;
	return true;
}

int bfs(Node start) {
	queue<Node> q;
	q.push(start);

	int visited[50][50] = {};
	visited[start.y][start.x] = 1;

	int cnt = 1;
	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int ny = now.y + dy[dir];
			int nx = now.x + dx[dir];
			if (!(0 <= ny && ny < N && 0 <= nx && nx < M))
				continue;
			if (board[ny][nx] == 0)
				continue;
			if (visited[ny][nx] != 0)
				continue;
			if (!isConnected(now, { ny, nx }, dir))
				continue;
			if (visited[now.y][now.x] + 1 > L)
				continue;
			cnt++;
			visited[ny][nx] = visited[now.y][now.x] + 1;
			q.push({ ny, nx });
		}
	}
	return cnt;
}


int solution() {
	return bfs({ R, C });
}

void input() {
	cin >> N >> M >> R >> C >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
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
		cout << "#" << tc << " " << solution() << "\n";

	}


	return 0;
}