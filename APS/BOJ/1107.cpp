#include <iostream>

using namespace std;

int N, M;
int notWork[10];
int cnt_min;
int cnt;
int channel_start;
int diff_min = 2147483647;
int len = 1;

void dfs(int level, int now) {
	if (len - 1 <= level && level <= len + 1) {
		if (diff_min >= abs(now - N)) {
			diff_min = abs(now - N);
			channel_start = now;
			cnt = level;
		}
	}
	// base case
	if (level == len + 1)
		return;
	if (now == 0)
		return;
	// recursive case
	for (int i = 0; i < 10; i++) {
		if (notWork[i] == 1)
			continue;
		dfs(level + 1, now * 10 + i);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int button;
		cin >> button;
		notWork[button] = 1;
	}
	
	int temp = N;
	while (temp >= 10) {
		temp /= 10;
		len++;
	}

	cnt_min = abs(N - 100);
	
	// ���ڸ� �ϳ��� ��� ���ϸ� +�� -�θ� �̵��ؾ���
	if (M == 10) {
		cout << cnt_min;
		return 0;
	}

	// ���ڸ� �ϳ��� ��� �����ϸ� ������ ������ ã��
	dfs(1, 0);
	for (int i = 1; i < 9; i++) {
		if (notWork[i] == 1)
			continue;
		dfs(1, i);
	}
	cnt_min = min(cnt_min, cnt + abs(channel_start - N));
	cout << cnt_min;
	return 0;
}

/*
0~9, +, -
0���� - -> �̵�X
N���� �̵��ϱ� ���� �ּ� �Է� Ƚ��
������ 100����
*/