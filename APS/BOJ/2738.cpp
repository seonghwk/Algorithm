#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> A, B;

void input() {
  cin >> N >> M;
  A.resize(N, vector<int>(M));
  B.resize(N, vector<int>(M));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> A[i][j];
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> B[i][j];
    }
  }
}

void solve() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cout << A[i][j] + B[i][j] << " ";
    }
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