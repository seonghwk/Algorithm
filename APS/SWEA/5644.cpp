#include <iostream>
#include <queue>

using namespace std;

struct Node {
	int x;
	int y;
};

struct Charger {
	int x;
	int y;
	int C;
	int P;
};

struct cmp {
	bool operator()(Charger a, Charger b) {
		if (a.P > b.P)
			return false;
		if (a.P < b.P)
			return true;
		return false;
	}
};

int board[11][11];
const int dx[] = { 0, 0, 1, 0, -1 };
const int dy[] = { 0, -1, 0, 1, 0 };
Node a, b;
int M, BC;
int move_info[2][100];
Charger charger_list[8];

int solution() {
	int ret = 0;
	int dir;

	for (int i = 0; i <= M; i++) {
		
		priority_queue<Charger, vector<Charger>, cmp> pq_a;
		priority_queue<Charger, vector<Charger>, cmp> pq_b;
		for (int j = 0; j < BC; j++) {
			Charger now = charger_list[j];
			if (abs(now.y - a.y) + abs(now.x - a.x) <= now.C) {
				pq_a.push(now);
			}
			if (abs(now.y - b.y) + abs(now.x - b.x) <= now.C) {
				pq_b.push(now);
			}
		}

		if (!pq_a.empty() && !pq_b.empty()) {
			Charger a_bc = pq_a.top();
			pq_a.pop();
			Charger b_bc = pq_b.top();
			pq_b.pop();
			if (a_bc.y == b_bc.y && a_bc.x == b_bc.x) {
				if (pq_a.empty() && pq_b.empty()) {
					ret += a_bc.P;
				}
				else if (pq_a.empty()) {
					ret += a_bc.P + pq_b.top().P;
				}
				else if (pq_b.empty()) {
					ret += b_bc.P + pq_a.top().P;
				}
				else {
					if (pq_a.top().P > pq_b.top().P)
						ret += b_bc.P + pq_a.top().P;
					else
						ret += a_bc.P + pq_b.top().P;
				}
			}
			else {
				ret += a_bc.P + b_bc.P;
			}
		}
		else if (!pq_a.empty()) {
			ret += pq_a.top().P;
		}
		else if (!pq_b.empty()) {
			ret += pq_b.top().P;
		}

		if (i == M)
			break;
		dir = move_info[0][i];
		a = { a.x + dx[dir], a.y + dy[dir] };
		dir = move_info[1][i];
		b = { b.x + dx[dir], b.y + dy[dir] };

	}


	return ret;
}

void input() {
	a = { 1,1 };
	b = { 10, 10 };

	cin >> M >> BC;
	for (int i = 0; i < M; i++)
		cin >> move_info[0][i];
	for (int i = 0; i < M; i++)
		cin >> move_info[1][i];
	for (int i = 0; i < BC; i++)
		cin >> charger_list[i].x >> charger_list[i].y >> charger_list[i].C >> charger_list[i].P;
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