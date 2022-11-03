#include <iostream>
#include <string.h>

using namespace std;

int n;
int dp[11];

int main() {

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> n;
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;
		for (int i = 4; i <= n; i++) {
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		}
		cout << dp[n] << "\n";
	}

	return 0;
}