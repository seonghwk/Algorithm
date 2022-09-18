#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
	int y;
	int x;
};

struct Dist {
	int id;
	int dist;
};

bool operator < (Dist a, Dist b) {
	if (a.dist < b.dist)
		return true;
	if (a.dist > b.dist)
		return false;
	return false;
}

int N, M;
int board[51][51];
vector<Node> v_home;
vector<Node> v_chicken;
vector<vector<Dist>> v_dist;
int visited[13];
int dist_min = 2147483647;

void count_min_dist() {
	int dist = 0;
	for (int i = 0; i < v_dist.size(); i++) {
		for (int j = 0; j < v_dist[i].size(); j++) {
			if (visited[v_dist[i][j].id] == 0)
				continue;
			dist += v_dist[i][j].dist;
			break;
		}
	}
	dist_min = min(dist_min, dist);
}

// ġŲ�� M�� ����
void dfs(int level, int cnt) {
	// base case
	if (cnt == M) {
		count_min_dist();
		return;
	}
	if (level == v_chicken.size())
		return;
	// recursive case
	// 1. ����
	dfs(level + 1, cnt);
	// 2. ����
	visited[level] = 1;
	dfs(level + 1, cnt + 1);
	visited[level] = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1)
				v_home.push_back({ i, j });
			else if (board[i][j] == 2)
				v_chicken.push_back({ i, j });
		}
	}

	for (int i = 0; i < v_home.size(); i++) {
		vector<Dist> v;
		Node now_home = v_home[i];
		for (int j = 0; j < v_chicken.size(); j++) {
			Node now_chicken = v_chicken[j];
			int dist = abs(now_home.y - now_chicken.y) + abs(now_home.x - now_chicken.x);
			v.push_back({ j, dist });
		}
		sort(v.begin(), v.end());
		v_dist.push_back(v);
	}

	dfs(0, 0);
	cout << dist_min;

	return 0;
}

/*
��ĭ(0), ġŲ(2), ��(1)
1-indexing
ġŲ �Ÿ�: ���� ���� ����� ġŲ�� ���� �Ÿ�
������ ġŲ �Ÿ� : ��� ���� ġŲ�Ÿ��� ��

ġŲ�� M���� �����
������ ġŲ �Ÿ��� ���� �۰ԵǴ� M�� ���� ���

*/