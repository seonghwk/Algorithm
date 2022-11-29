#include <iostream>
#include <list>
#include <queue>

using namespace std;

int N, K;
// queue<int> q;
list<int> survivors;
// void input() {
//   cin >> N >> K;
//   for (int i = 1; i <= N; i++) {
//     q.push(i);
//   }
// }

// void solve() {
//   cout << "<";
//   for (int i = 0; i < N; i++) {
//     for (int j = 0; j < K - 1; j++) {
//       q.push(q.front());
//       q.pop();
//     }
//     if (i == N - 1) {
//       cout << q.front() << ">";
//       return;
//     }
//     cout << q.front() << ", ";
//     q.pop();
//   }
// }

void input() {
  cin >> N >> K;
  for (int i = 1; i <= N; i++) {
    survivors.push_back(i);
  }
}

void solve() {
  cout << "<";
  list<int>::iterator kill = survivors.begin();
  while (!survivors.empty()) {
    for (int i = 0; i < K - 1; i++) {
      kill++;
      if (kill == survivors.end()) kill = survivors.begin();
    }
    if (survivors.size() == 1) {
      cout << *kill << ">";
      return;
    }
    cout << *kill << ", ";
    kill = survivors.erase(kill);
    if (kill == survivors.end()) kill = survivors.begin();
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