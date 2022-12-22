#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int F;
vector<int> parent;
vector<int> groupCnt;
unordered_map<string, int> mp;

int Find(int now) {
  if (parent[now] == now) return now;
  return parent[now] = Find(parent[now]);
}

void Union(int a, int b) {
  int pa = Find(a);
  int pb = Find(b);

  if (pa == pb) return;
  parent[pb] = pa;
  groupCnt[pa] += groupCnt[pb];
  groupCnt[pb] = 0;
}

void input() {
  parent.clear();
  groupCnt.clear();
  mp.clear();
  cin >> F;
  int id = 0;
  string a, b;
  for (int i = 0; i < F; i++) {
    cin >> a >> b;
    if (mp.find(a) == mp.end()) {
      parent.push_back(id);
      groupCnt.push_back(1);
      mp[a] = id++;
    }
    if (mp.find(b) == mp.end()) {
      parent.push_back(id);
      groupCnt.push_back(1);
      mp[b] = id++;
    }
    Union(mp[a], mp[b]);
    cout << groupCnt[parent[mp[a]]] << "\n";
  }
}

void solve() { return; }

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

  return 0;
}