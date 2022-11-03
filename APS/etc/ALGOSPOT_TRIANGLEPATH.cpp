#include <iostream>
#include <string.h>

using namespace std;

int n, triangle[100][100];
int cache[100][100];

int path(int y, int x) {
	// base case
	if (y == n - 1)
		return triangle[y][x];
	// recursive case
	int& ret = cache[y][x];
	if (ret != -1)
		return ret;
	return ret = max(path(y + 1, x), path(y + 1, x + 1)) + triangle[y][x];
}

int solution() {
	return path(0, 0);
}

void input() {
	memset(cache, -1, sizeof(cache));
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> triangle[i][j];
		}
	}
}

int main() {
	int C;
	cin >> C;
	for (int tc = 1; tc <= C; tc++) {
		input();
		cout << solution() << "\n";
	}

	return 0;
}