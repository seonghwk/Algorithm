#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
vector<string> arr;

void input() {
  cin >> n;
  arr.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
}

void solve() {
  for (int i = 0; i < n; i++) {
    int len = arr[i].length();
    if (len > 10)
      cout << arr[i][0] << len - 2 << arr[i][len - 1];
    else
      cout << arr[i];
    cout << "\n";
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