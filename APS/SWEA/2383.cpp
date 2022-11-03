#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
	int y;
	int x;
};

struct Move {
	int id;
	int dist;
};

struct cmp {
	bool operator()(Move a, Move b) {
		if (a.dist < b.dist)
			return false;
		if (a.dist > b.dist)
			return true;
		return false;
	}
};

int N;
int board[10][10];
int max_time;
int min_time;
vector<Node> stairs;
vector<Node> person;
vector<int> selected[2];

void simulate() {
	priority_queue<Move, vector<Move>, cmp> pq[2];

	for (int stair = 0; stair < 2; stair++) {
		for (int i = 0; i < selected[stair].size(); i++) {
			Node from = person[selected[stair][i]];
			Node to = stairs[stair];
			int dist = abs(from.y - to.y) + abs(from.x - to.x);
			pq[stair].push({ selected[stair][i], dist });
		}
	}
	max_time = 0;
	for (int stair = 0; stair < 2; stair++) {
		int DAT[100] = {};
		while (!pq[stair].empty()) {
			Move now = pq[stair].top();
			pq[stair].pop();

			// µµÂø½Ã°£ = now.dist
			int available = now.dist+1;
			for (int i = now.dist; i < now.dist + board[stairs[stair].y][stairs[stair].x]; i++) {
				if (DAT[i] >= 3)
					available = i + 1;
			}
			for (int i = available; i < available + board[stairs[stair].y][stairs[stair].x]; i++) {
				DAT[i]++;
			}
		}
		int time = 0;
		for (int i = 0; i < 100; i++) {
			if (DAT[i] != 0)
				time = i + 1;
		}
		max_time = max(time, max_time);
	}
}

void dfs(int level) {
	// base case
	if (level == person.size()) {
		simulate();
		min_time = min(min_time, max_time);
		return;
	}

	// recursive case
	selected[0].push_back(level);
	dfs(level + 1);
	selected[0].pop_back();
	selected[1].push_back(level);
	dfs(level + 1);
	selected[1].pop_back();
}

void solution() {
	dfs(0);
}

void input() {
	min_time = 2147483647;
	stairs.clear();
	person.clear();
	selected[0].clear();
	selected[1].clear();
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1)
				person.push_back({ i, j });
			else if (board[i][j] >= 2)
				stairs.push_back({ i, j });
		}
	}
}

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		input();
		solution();
		cout << "#" << tc << " " << min_time << "\n";
	}
	return 0;
}