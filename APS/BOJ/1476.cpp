#include <iostream>

using namespace std;

int E, S, M;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> E >> S >> M;
	int year = 0;
	int e, s, m;
	while (true) {
		e = year % 15 + 1;
		s = year % 28 + 1;
		m = year % 19 + 1;
		if (e == E && s == S && m == M)
			break;
		year++;
	}

	cout << year + 1;

	return 0;
}

/*
연도 표시, 수 3개 -> 지구(E), 태양(S), 달(M)
[1,15] [1,28] [1,19]
범위 넘어가면 1

*/