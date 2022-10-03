#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, X;
	string cmd;
	cin >> N;
	stack<int> s;
	for (int i = 0; i < N; i++) {
		cin >> cmd;
		if (cmd == "push") {
			cin >> X;
			s.push(X);
		}
		else if (cmd == "pop") {
			if (s.empty()) {
				cout << "-1\n";
				continue;
			}
			cout << s.top() << "\n";
			s.pop();
		}
		else if (cmd == "size") {
			cout << s.size() << "\n";
		}
		else if (cmd == "empty") {
			if (s.empty()) {
				cout << "1\n";
				continue;
			}
			cout << "0\n";
		}
		else if (cmd == "top") {
			if (s.empty()) {
				cout << "-1\n";
				continue;
			}
			cout << s.top() << "\n";

		}
	}


	return 0;
}