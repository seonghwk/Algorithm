#include <iostream>
#include <list>

using namespace std;

int N, K;

void input() { cin >> N >> K; }

void solve() {
  list<int> lt;
  for (int i = 1; i <= N; i++) {
    lt.push_back(i);
  }
  list<int>::iterator it = lt.begin();
  while (N > 2) {
    it = lt.erase(it);
    N--;
    if (it == lt.end()) it = lt.begin();
    for (int i = 0; i < (K - 1) % N; i++) {
      it++;
      if (it == lt.end()) it = lt.begin();
    }
  }
  cout << lt.front() << " " << lt.back() << "\n";
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