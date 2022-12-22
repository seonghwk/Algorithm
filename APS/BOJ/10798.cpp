#include <iostream>
#include <vector>

using namespace std;

vector<string> v(5);
void input() {
  for (int i = 0; i < 5; i++) {
    cin >> v[i];
  }
}

void solve() {
  for (int j = 0; j < 15; j++) {
    for (int i = 0; i < 5; i++) {
      if (j >= v[i].length()) continue;
      cout << v[i][j];
    }
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