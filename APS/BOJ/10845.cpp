#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, X;
	int front, back;
	string cmd;
	cin >> N;
	queue<int> q;
	for (int i = 0; i < N; i++) {
		cin >> cmd;
		if (cmd == "push") {
			cin >> X;
			if (q.empty()) {
				front = X;
			}
			q.push(X);
			back = X;
		}
		else if (cmd == "pop") {
			if (q.empty()) {
				cout << "-1\n";
				continue;
			}
			cout << q.front() << "\n";
			q.pop();
			if (!q.empty())
				front = q.front();
		}
		else if (cmd == "size") {
			cout << q.size() << "\n";
		}
		else if (cmd == "empty") {
			if (q.empty()) {
				cout << "1\n";
				continue;
			}
			cout << "0\n";
		}
		else if (cmd == "front") {
			if (q.empty()) {
				cout << "-1\n";
				continue;
			}
			cout << front << "\n";
		}
		else if (cmd == "back") {
			if (q.empty()) {
				cout << "-1\n";
				continue;
			}
			cout << back << "\n";
		}
	}


	return 0;
}