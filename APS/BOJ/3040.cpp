#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
vector<int> path;

void input() {
  arr.resize(9);
  for (int i = 0; i < 9; i++) {
    cin >> arr[i];
  }
}

void dfs(int now, int sum) {
  // base case
  if (now == 10) return;
  if (sum > 100) return;
  if (sum == 100 && path.size() == 7) {
    for (int i = 0; i < path.size(); i++) {
      cout << arr[path[i]] << "\n";
    }
    return;
  }

  // recursive case
  path.push_back(now);
  dfs(now + 1, sum + arr[now]);
  path.pop_back();
  dfs(now + 1, sum);
}

void solve() { dfs(0, 0); }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}