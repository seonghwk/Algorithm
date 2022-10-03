//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int N, M;
//int parent[1001];
//int groupCnt[1001];
//
//int Find(int now) {
//	if (parent[now] == now)
//		return now;
//	parent[now] = Find(parent[now]);
//	return parent[now];
//}
//
//void Union(int a, int b) {
//	int pa = Find(a);
//	int pb = Find(b);
//
//	if (pa == pb)
//		return;
//
//	parent[pb] = pa;
//	groupCnt[pa] += groupCnt[pb];
//	groupCnt[pb] = 0;
//}
//
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	cin >> N >> M;
//	for (int i = 1; i <= N; i++) {
//		parent[i] = i;
//		groupCnt[i] = 1;
//	}
//	for (int i = 0; i < M; i++) {
//		int from, to;
//		cin >> from >> to;
//		Union(from, to);
//	}
//	int cnt = 0;
//	for (int i = 1; i <= N; i++) {
//		if (groupCnt[i] == 0)
//			continue;
//		cnt++;
//	}
//	
//	cout << cnt;
//
//	return 0;
//}


#include <iostream>
#include <vector>
#include <queue>


using namespace std;

int N, M;
vector<int> v[1001];
int visited[1001];

void bfs(int start) {
	queue<int> q;
	q.push(start);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			if (visited[next] != 0)
				continue;
			visited[next] = 1;
			q.push(next);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}

	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (visited[i] != 0)
			continue;
		cnt++;
		visited[i] = 1;
		bfs(i);
	}

	cout << cnt;

	return 0;
}