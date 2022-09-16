#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

bool isHansu(int N) {
	v.clear();
	while (N != 0) {
		v.push_back(N % 10);
		N /= 10;
	}
	if (v.size() <= 2)
		return true;
	int diff = v[1] - v[0];
	for (int i = 1; i < v.size() - 1; i++) {
		if (diff != v[i + 1] - v[i])
			return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int N;
	cin >> N;
	int cnt = 0;
	while (N >= 1) {
		if (isHansu(N)) {
			cnt++;
		}
		N--;
	}
	cout << cnt;

	return 0;
}
