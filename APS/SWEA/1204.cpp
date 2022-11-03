#include <iostream>
#include <string.h>

using namespace std;

int arr[101];

void input() {
	memset(arr, 0, sizeof(arr));
	int tc;
	cin >> tc;

	for (int i = 0; i < 1000; i++) {
		int score;
		cin >> score;
		arr[score]++;
	}
}

int solution() {
	int max_idx = 0;
	for (int i = 0; i <= 100; i++) {
		if (arr[max_idx] <= arr[i])
			max_idx = i;
	}
	return max_idx;
}

int main() {

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		input();
		cout << "#" << tc << " " << solution() << "\n";
	}
}