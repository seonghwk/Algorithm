#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Comb {
  int a, b;
};

int N;
vector<int> arr;
unordered_map<int, vector<Comb>> mp;

void input() {
  cin >> N;
  arr.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }
}

void solve() {
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      mp[arr[i] + arr[j]].push_back({i, j});
    }
  }

  int cnt = 0;
  for (int i = 0; i < N; i++) {
    if (mp[arr[i]].size() != 0) {
      for (int j = 0; j < mp[arr[i]].size(); j++) {
        if (mp[arr[i]][j].a == i || mp[arr[i]][j].b == i) continue;
        cnt++;
        break;
      }
    }
  }
  cout << cnt;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}

/*
 */