#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<string> v;

bool cmp(string a, string b) {
  if (a.length() < b.length()) return true;
  if (a.length() > b.length()) return false;
  for (int i = 0; i < a.length(); i++) {
    if (a[i] < b[i]) return true;
    if (a[i] > b[i]) return false;
  }
  return false;
}

void input() {
  cin >> N;
  v.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> v[i];
  }
}

void solve() {
  sort(v.begin(), v.end(), cmp);
  cout << v[0] << "\n";
  for (int i = 1; i < N; i++) {
    if (v[i] == v[i - 1]) continue;
    cout << v[i] << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}
