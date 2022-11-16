#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> A;
vector<int> B;

void input() {
  cin >> N;
  A = vector<int>(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  cin >> M;
  B = vector<int>(M);
  for (int i = 0; i < M; i++) {
    cin >> B[i];
  }
}

int binarySearch(int target) {
  int left = 0;
  int right = A.size() - 1;
  int mid;
  while (left <= right) {
    mid = left + (right - left) / 2;
    if (A[mid] == target) return 1;
    if (A[mid] > target) right = mid - 1;
    if (A[mid] < target) left = mid + 1;
  }
  return 0;
}

void solution() {
  sort(A.begin(), A.end());
  for (int i = 0; i < M; i++) {
    cout << binarySearch(B[i]) << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solution();

  return 0;
}