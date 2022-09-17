#include <iostream>
#include <algorithm>

using namespace std;

int L, C;
char ch[15];
char password[15];
int cnt_vowel;

bool isVowel(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return true;
	return false;
}

void dfs(int level, int start) {
	// base case
	if (level == L) {
		if (cnt_vowel < 1 || L - cnt_vowel < 2)
			return;
		cout << password << "\n";
		return;
	}
	// recursive case
	for (int i = start; i < C; i++) {
		password[level] = ch[i];
		if (isVowel(ch[i])) {
			cnt_vowel++;
			dfs(level + 1, i + 1);
			cnt_vowel--;
		}
		else
			dfs(level + 1, i + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		cin >> ch[i];
	}
	sort(ch, ch + C);
	dfs(0, 0);

	return 0;
}