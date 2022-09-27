#include <iostream>

using namespace std;

int N;
int stairs[301];
int dp[301];

int dfs(int level, int consecutive) {
	// level번째 계단에서 앞으로 얻을 수 있는 최대 점수를 반환
	
	// base case
	if (level == N)
		return stairs[level];
	if (dp[level] != 0)
		return dp[level];

	// recursive case
	int ret = -2147483648;
	if (consecutive < 2 && level + 1 <= N)
		ret = max(ret, dfs(level + 1, consecutive + 1));
	if (level + 2 <= N)
		ret = max(ret, dfs(level + 2, 1));
	dp[level] = ret + stairs[level];
	return dp[level];

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> stairs[i];
	}
	cout << dfs(0, 0);

	return 0;
}