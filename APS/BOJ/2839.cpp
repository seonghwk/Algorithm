#include <iostream>
#include <string.h>

using namespace std;

int N;
int dp[5001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	memset(dp, -1, sizeof(dp));
	dp[3] = 1;
	dp[5] = 1;
	for (int i = 6; i <= N; i++) {
		int a = 2147483647;
		if (dp[i - 3] != -1)
			a = min(a, dp[i - 3] + 1);
		if (dp[i - 5] != -1)
			a = min(a, dp[i - 5] + 1);

		if (a == 2147483647)
			continue;
		dp[i] = a;
	}
	cout << dp[N];


	return 0;
}
