#include <iostream>

using namespace std;

int N, S;
int arr[20];
int cnt;

void dfs(int level, int sum) {
	// base case
	if (level == N) {
		if (sum == S)
			cnt++;
		return;
	}
	// recursive case
	dfs(level + 1, sum);
	dfs(level + 1, sum + arr[level]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	dfs(0, 0);
	if (S == 0)
		cnt--;
	cout << cnt;
	return 0;
}