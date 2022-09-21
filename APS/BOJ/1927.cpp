#include <iostream>
#include <queue>

using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		if (x != 0) {
			pq.push(x);
			continue;
		}
		if (pq.empty()) {
			cout << 0 << "\n";
			continue;
		}
		cout << pq.top() << "\n";
		pq.pop();
	}

	return 0;
}