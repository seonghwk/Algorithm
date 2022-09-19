#include <iostream>

using namespace std;

int main() {
	int start = 1;
	int end = 100;
	while (start <= end) {
		int mid = start + (end - start) / 2;
		cout << mid << "\n";
		int state;
		cin >> state;
		if (state == 66) {
			end = mid - 1;
		}
		if (state == 33) {
			start = mid + 1;
		}
	}

	return 0;
}