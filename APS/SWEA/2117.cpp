#include <iostream>
#include <queue>

using namespace std;

struct Node {
	int y;
	int x;
};

int N, M;
int board[20][20];
const int dy[] = { -1, 1, 0, 0 };
const int dx[] = { 0, 0, -1, 1 };

int bfs(Node start) {
	queue<Node> q;
	q.push(start);
	int visited[20][20] = {};
	visited[start.y][start.x] = 1;

	int house_cnt = 0;
	int house_cnt_max = -1;
	int cur_range = 1;
	int cost, earning;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		if (board[now.y][now.x] == 1)
			house_cnt++;

		cur_range = visited[now.y][now.x];
		cost = cur_range * cur_range + (cur_range - 1) * (cur_range - 1);
		earning = house_cnt * M;
		if (earning >= cost) {
			house_cnt_max = max(house_cnt_max, house_cnt);
		}

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			if (!(0 <= ny && ny < N && 0 <= nx && nx < N))
				continue;
			if (visited[ny][nx] != 0)
				continue;
			visited[ny][nx] = visited[now.y][now.x] + 1;
			q.push({ ny, nx });
		}
	}
	return house_cnt_max;
}

int solution() {
	int house_cnt_max = -1;

	if (N == 20 && M == 3)
		int de = -1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == 10 && j == 10)
				int dd = 1;
			house_cnt_max = max(house_cnt_max, bfs({ i, j }));
		}
	}

	return house_cnt_max;
}

void input() {
	cin >> N >> M;
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