#include <iostream>
#include <stack>

using namespace std;

int K;
stack<int> st;

void input() {
  cin >> K;
  int num;
  for (int i = 0; i < K; i++) {
    cin >> num;
    if (num == 0)
      st.pop();
    else
      st.push(num);
  }
}

void solve() {
  int sum = 0;
  while (!st.empty()) {
    sum += st.top();
    st.pop();
  }
  cout << sum;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}