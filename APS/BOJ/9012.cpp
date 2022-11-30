#include <iostream>
#include <stack>

using namespace std;

string str;
stack<char> s_left, s_right;

void input() {
  s_left = stack<char>();
  s_right = stack<char>();
  cin >> str;
  for (int i = 0; i < str.length(); i++) {
    s_left.push(str[i]);
  }
}

void solve() {
  while (true) {
    if (s_left.empty()) break;
    s_right.push(s_left.top());
    s_left.pop();
    if (s_left.empty()) break;
    while (!s_left.empty() && !s_right.empty()) {
      if (s_left.top() == '(' && s_right.top() == ')') {
        s_left.pop();
        s_right.pop();
        continue;
      }
      break;
    }
  }
  if (s_left.empty() && s_right.empty())
    cout << "YES\n";
  else
    cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;
  for (int tc = 1; tc <= T; tc++) {
    input();
    solve();
  }

  return (0);
}