#include <iostream>
#include <queue>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;
  int x;
  priority_queue<int> pq;
  for (int i = 0; i < N; i++) {
    cin >> x;
    if (x == 0) {
      if (pq.empty()) {
        cout << "0";
      } else {
        cout << pq.top();
        pq.pop();
      }
      cout << "\n";
    } else {
      pq.push(x);
    }
  }
  return 0;
}