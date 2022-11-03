#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[100];
int max_height;

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {

		max_height = -1;

		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
			max_height = max(max_height, arr[i]);
		}

		int odd = 0;
		int even = 0;
		for (int i = 0; i < N; i++) {
			int diff = max_height - arr[i];
			if (diff % 2 == 1) {
				odd++;
			}
			even += diff / 2;
		}
		while (even * 2 - odd * 2 + 1 > 4) {
			even--;
			odd += 2;
		}
		
		cout << "#" << tc << " " << max(odd * 2 - 1, even * 2) << "\n";
	}
	return 0;
}