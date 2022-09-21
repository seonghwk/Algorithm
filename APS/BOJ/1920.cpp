#include <iostream>
#include <unordered_map>

using namespace std;

int N, M;
unordered_map<int, int> mp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int val;
		cin >> val;
		mp[val] = 1;
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int val;
		cin >> val;
		cout << mp[val] << "\n";
	}

	return 0;
}