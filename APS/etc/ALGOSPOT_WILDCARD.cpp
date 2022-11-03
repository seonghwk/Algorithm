#include <iostream>
#include <algorithm>

using namespace std;

string W;
int n;
string arr[50];

bool isValid(int idx) {
	int i = 0;
	int j = 0;
	string now = arr[idx];
	while (true) {
		if (now[i] == W[j]) {
			if (now[i] == 0) {
				return true;
			}
			i++;
			j++;
			continue;
		}
		// now[i] != W[j]
		if (now[i] == 0) {
			while (W[j] == '*')
				j++;
			if (W[j] == 0)
				return true;
			return false;
		}
		if (W[j] == 0) {
			return false;
		}
		if (W[j] == '?') {
			i++;
			j++;
			continue;
		}
		if (W[j] == '*') {
			while (W[j] == '*')
				j++;
			while (now[i] != W[j] && now[i] != 0)
				i++;
			continue;
		}
		return false;
	}

}

int main() {
	int C;
	cin >> C;
	for (int tc = 1; tc <= C; tc++) {
		cin >> W;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		sort(arr, arr + n);
		for (int i = 0; i < n; i++) {
			if (isValid(i))
				cout << arr[i] << "\n";
		}

	}

	return 0;
}