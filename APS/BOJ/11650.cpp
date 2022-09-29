#include <iostream>
#include <queue>

using namespace std;

struct Node {
	int x;
	int y;
};

struct cmp {
	bool operator()(Node a, Node b) {
		if (a.x < b.x)
			return false;
		if (a.x > b.x)
			return true;
		if (a.y < b.y)
			return false;
		if (a.y > b.y)
			return true;
		return false;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	priority_queue<Node, vector<Node>, cmp> pq;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		pq.push({ x, y });
	}
	while (!pq.empty()) {
		cout << pq.top().x << " " << pq.top().y << "\n";
		pq.pop();
	}
	return 0;
}