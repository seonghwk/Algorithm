#include <iostream>

using namespace std;

int arr[15];
int n;
int cnt;

bool isValid(int row) {
	for (int i = 0; i < row; i++) {
		if (arr[i] == arr[row])
			return false;
		if (arr[i] == arr[row] - (row - i))
			return false;
		if (arr[i] == arr[row] + (row - i))
			return false;
	}
	return true;
}

void dfs(int row) {
	// base case
	if (row == n) {
		cnt++;
		return;
	}
	// recursive case
	for (int i = 0; i < n; i++) {
		arr[row] = i;
		if (!isValid(row))
			continue;
		dfs(row + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	dfs(0);
	cout << cnt;

	return 0;
}