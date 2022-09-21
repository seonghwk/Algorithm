#include <iostream>

using namespace std;

int n, m;
int parent[1000001];

int Find(int now) {
	if (parent[now] == now)
		return now;
	parent[now] = Find(parent[now]);
	return parent[now];
}

void Union(int a, int b) {
	int pa = Find(a);
	int pb = Find(b);

	if (pa == pb)
		return;

	parent[pb] = pa;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int mode, a, b;
		cin >> mode >> a >> b;
		if (mode == 0)
			Union(a, b);
		else {
			if (Find(a) == Find(b))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}

	return 0;
}