#include <iostream>

using namespace std;

int N;

bool isCreator(int num) {
	int sum = num;
	while (num != 0) {
		sum += num % 10;
		num /= 10;
	}
	if (sum == N)
		return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> N;

	for (int i = 1; i <= N; i++) {
		if (isCreator(i)) {
			cout << i;
			return 0;
		}
	}
	cout << 0;

	return 0;
}
