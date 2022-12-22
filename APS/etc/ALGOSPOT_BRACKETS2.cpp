#include <iostream>
#include <stack>

using namespace std;

string str;
stack<char> st;

void input() {
  cin >> str;
  st = stack<char>();
  for (int i = 0; i < str.length(); i++) {
    st.push(str[i]);
  }
}

bool isCorrect() {
  stack<char> st2;
  while (true) {
    st2.push(st.top());
    st.pop();
    if (st.empty()) return false;
    while (true) {
      int flag = 0;
      if (st.top() == '[' && st2.top() == ']') flag = 1;
      if (st.top() == '(' && st2.top() == ')') flag = 1;
      if (st.top() == '{' && st2.top() == '}') flag = 1;
      if (flag == 0) break;
      st.pop();
      st2.pop();
      if (st.empty() || st2.empty()) break;
    }
    if (st.empty()) break;
  }
  return st2.empty();
}

bool wellMatched(const string& formula) {
  const string opening("([{"), closing(")]}");
  stack<char> openStack;
  for (int i = 0; i < formula.size(); i++) {
    if (opening.find(formula[i]) != -1) {
      openStack.push(formula[i]);
    } else {
      if (openStack.empty()) return false;
      if (opening.find(openStack.top()) != closing.find(formula[i]))
        return false;
      openStack.pop();
    }
  }
  return openStack.empty();
}

void solve() {
  // bool result = isCorrect();
  bool result = wellMatched(str);
  if (result)
    cout << "YES\n";
  else
    cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int C;
  cin >> C;
  for (int tc = 1; tc <= C; tc++) {
    input();
    solve();
  }

  return 0;
}
