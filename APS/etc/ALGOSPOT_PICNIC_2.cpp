#include <iostream>
#include<string.h>

using namespace std;

int n, m;
bool areFriends[10][10];
bool taken[10];

int countPairings(bool taken[10]) {
	int firstFree = -1;
	for (int i = 0; i < n; i++) {
		if (!taken[i]) {
			firstFree = i;
			break;
		}
	}
	if (firstFree == -1)
		return 1;
	int ret = 0;
	for (int pairWith = firstFree + 1; pairWith < n; pairWith++) {
		if (!taken[pairWith] && areFriends[firstFree][pairWith]) {
			taken[firstFree] = taken[pairWith] = true;
			ret += countPairings(taken);
			taken[firstFree] = taken[pairWith] = false;
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int C;
	cin >> C;
	for (int tc = 1; tc <= C; tc++) {
		memset(areFriends, 0, sizeof(areFriends));

		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int from, to;
			cin >> from >> to;
			areFriends[from][to] = areFriends[to][from] = true;
		}
		cout << countPairings(taken) << "\n";
	}

	return 0;
}