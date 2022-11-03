#include <iostream>
#include <vector>

using namespace std;

struct Node {
	int y;
	int x;
};

int N, K;
int max_height;
int max_dist;
int board[8][8];
int visited[8][8];
vector<Node> v;

const int dy[] = { -1, 1, 0, 0 };
const int dx[] = { 0, 0, -1, 1 };

void dfs(int y, int x, int dist, int digged) {
	max_dist = max(max_dist, dist);
	// base case
	
	// recursive case
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (!(0 <= ny && ny < N && 0 <= nx && nx < N))
			continue;
		if (digged == 1 && (board[y][x] <= board[ny][nx]))
			continue;
		if (visited[ny][nx] != 0)
			continue;


		if (board[y][x] > board[ny][nx]) {
			visited[ny][nx] = 1;
			dfs(ny, nx, dist + 1, digged);
			visited[ny][nx] = 0;
		}
		else if (digged == 0 && (board[y][x] + K > board[ny][nx])){
			int temp = board[ny][nx];
			board[ny][nx] = board[y][x] - 1;
			visited[ny][nx] = 1;
			dfs(ny, nx, dist + 1, 1);
			visited[ny][nx] = 0;
			board[ny][nx] = temp;
		}
	}
}

void solution() {

	for (int i = 0; i < v.size(); i++) {
		visited[v[i].y][v[i].x] = 1;
		dfs(v[i].y, v[i].x, 1, 0);
		visited[v[i].y][v[i].x] = 0;
	}

}

void input() {
	max_height = 0;
	max_dist = 0;
	v.clear();

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			max_height = max(max_height, board[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] != max_height)
				continue;
			v.push_back({ i, j });
		}
	}
}

int main() {

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		input();
		solution();
		cout << "#" << tc << " " << max_dist << "\n";
	}

	return 0;
}