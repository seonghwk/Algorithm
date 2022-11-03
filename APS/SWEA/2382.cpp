#include <iostream>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

struct Micro {
	int y;
	int x;
	int dir;
};

struct Order {
	int id;
	int cnt;
};

struct cmp {
	bool operator()(Order a, Order b) {
		if (a.cnt > b.cnt)
			return false;
		if (a.cnt < b.cnt)
			return true;
		return false;
	}
};

const int dy[] = {0, -1, 1, 0, 0 };
const int dx[] = {0, 0, 0, -1, 1 };

int N, M, K;
int board[100][100];
vector<Micro> v;

int parent[1001];
int groupCnt[1001];

int Find(int now) {
	if (now == parent[now])
		return now;
	parent[now] = Find(parent[now]);
	return parent[now];
}

void Union(int a, int b) {
	int pa = Find(a);
	int pb = Find(b);

	if (pa == pb)
		return;

	if (groupCnt[pb] > groupCnt[pa]) {
		parent[pa] = pb;
		groupCnt[pb] += groupCnt[pa];
		groupCnt[pa] = 0;
	}
	else {
		parent[pb] = pa;
		groupCnt[pa] += groupCnt[pb];
		groupCnt[pb] = 0;
	}
}

int solution() {
	for (int mv = 0; mv < M; mv++) {
		memset(board, 0, sizeof(board));
		priority_queue<Order, vector<Order>, cmp> pq;
		for (int i = 1; i <= K; i++) {
			Order now;
			now.id = i;
			now.cnt = groupCnt[i];
			pq.push(now);
		}
		while (!pq.empty()){
			Order now_order = pq.top();
			pq.pop();

			if (groupCnt[now_order.id] == 0)
				continue;

			Micro now = v[now_order.id];
			int ny = now.y + dy[now.dir];
			int nx = now.x + dx[now.dir];

			if (ny == 0 || ny == N - 1 || nx == 0 || nx == N - 1) {
				groupCnt[now_order.id] /= 2;
				if (ny == N - 1) v[now_order.id].dir = 1;
				if (ny == 0) v[now_order.id].dir = 2;
				if (nx == N - 1) v[now_order.id].dir = 3;
				if (nx == 0) v[now_order.id].dir = 4;
			}
			v[now_order.id].y = ny;
			v[now_order.id].x = nx;

			if (board[ny][nx] != 0) {
				Union(board[ny][nx], now_order.id);
			}
			board[ny][nx] = parent[now_order.id];
		}
	}
	int cnt = 0;
	for (int i = 1; i <= K; i++) {
		cnt += groupCnt[i];
	}
	return cnt;
}


void input() {
	v = vector<Micro>();
	memset(parent, 0, sizeof(parent));
	memset(groupCnt, 0, sizeof(groupCnt));

	v.push_back({});
	cin >> N >> M >> K;
	for (int i = 1; i <= K; i++) {
		parent[i] = i;
		Micro now;
		cin >> now.y >> now.x >> groupCnt[i] >> now.dir;
		v.push_back(now);
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