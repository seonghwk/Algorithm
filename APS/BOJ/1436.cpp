#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

bool isDoomNum(int n) {
	v.clear();
	while (n != 0) {
		v.push_back(n % 10);
		n /= 10;
	}
	int cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] != 6) {
			cnt = 0;
			continue;
		}
		cnt++;
		if (cnt >= 3)
			return true;
	}
	return false;
}

int main() {

	int n;
	cin >> n;

	int num = 666;
	int cnt = 0;
	while (true) {
		if (isDoomNum(num))
			cnt++;
		if (cnt == n) {
			cout << num;
			break;
		}
		num++;
	}

	return 0;
}