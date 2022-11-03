#include <iostream>

using namespace std;

int N;
int sign_cnt[4];
int arr[12];
int max_val;
int min_val;

void dfs(int level, int val) {
	// base case
	if (level == N-1) {
		max_val = max(val, max_val);
		min_val = min(val, min_val);
		return;
	}

	// rescursive case
	for (int i = 0; i < 4; i++) {
		if (sign_cnt[i] == 0)
			continue;
		
		sign_cnt[i]--;

		if (i == 0)
			dfs(level + 1, val + arr[level + 1]);
		else if (i == 1)
			dfs(level + 1, val - arr[level + 1]);
		else if (i == 2)
			dfs(level + 1, val * arr[level + 1]);
		else if (i == 3)
			dfs(level + 1, val / arr[level + 1]);

		
		sign_cnt[i]++;
	}
}

int solution() {
	int ret = 0;

	dfs(0, arr[0]);
	ret = max_val - min_val;

	return ret;
}

void input() {
	max_val = -2147483648;
	min_val = 2147483647;
	cin >> N;
	for (int i = 0; i < 4; i++) {
		cin >> sign_cnt[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
}

int main() {

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		input();
		cout << "#" << tc << " " << solution() << "\n";
	}

	return 0;
}