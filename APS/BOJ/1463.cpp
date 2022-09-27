#include <iostream>

using namespace std;

int dp[1000001];

int dfs(int num) {
	// base case
	if (num == 1)
		return 0;
	if (dp[num] != 0)
		return dp[num];
	// recursive case
	int ret = 2147483647;
	if (num % 3 == 0)
		ret = min(ret, dfs(num / 3) + 1);
	if (num % 2 == 0)
		ret = min(ret, dfs(num / 2) + 1);
	ret = min(ret, dfs(num - 1) + 1);
	dp[num] = ret;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	cout << dfs(N);

	return 0;
}