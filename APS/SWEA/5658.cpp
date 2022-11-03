#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

int N, K;
string lock_str;

int hex_to_dec(string hex) {
	int ret = 0;
	for (int i = hex.length() - 1; i >= 0; i--) {
		char digit = hex[i];
		if ('0' <= digit && digit <= '9') {
			ret += (digit - '0') * pow(16, hex.length() -1 - i);
		}
		else {
			ret += (digit - 'A' + 10) * pow(16, hex.length() - 1 - i);
		}
	}
	return ret;
}

int solution() {
	unordered_map<int, int> mp;
	for (int i = 0; i < N / 4; i++) {
		for (int j = 0; j < 4; j++) {
			int num = hex_to_dec(lock_str.substr(i + (N / 4) * j, N / 4));
			mp[num]++;
		}
	}
	vector<int> v;
	for (auto it = mp.begin(); it != mp.end(); it++) {
		v.push_back((*it).first);
	}
	sort(v.begin(), v.end(), greater<int>());
	return v[K-1];
}

void input() {
	cin >> N >> K;
	cin >> lock_str;
	lock_str = lock_str + lock_str;
}

int main() {
	
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		input();
		cout << "#" << tc << " " << solution() << "\n";
	}

	return 0;
}