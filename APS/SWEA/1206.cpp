#include <iostream>

using namespace std;

int N;
int height[1000];

int solution() {
	int cnt = 0;
	for (int i = 0 + 2; i < N - 2; i++) {
		if (height[i] <= height[i - 2])
			continue;
		if (height[i] <= height[i - 1])
			continue;
		if (height[i] <= height[i + 1])
			continue;
		if (height[i] <= height[i + 2])
			continue;
		cnt += min(height[i] - height[i - 2], min(height[i] - height[i - 1], min(height[i] - height[i + 1], height[i] - height[i + 2])));
	}

	return cnt;
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> height[i];
	}
}

int main() {

	for (int tc = 1; tc <= 10; tc++) {
		input();
		cout << "#" << tc << " " << solution() << "\n";
	}

	return 0;
}