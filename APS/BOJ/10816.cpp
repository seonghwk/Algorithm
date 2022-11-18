#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int N, M;
unordered_map<int, int> deck;
vector<int> target;

void input() {
  cin >> N;
  int num;
  for (int i = 0; i < N; i++) {
    cin >> num;
    deck[num]++;
  }
  cin >> M;
  target = vector<int>(M);
  for (int i = 0; i < M; i++) {
    cin >> target[i];
  }
}

void solution() {
  for (int i = 0; i < target.size(); i++) {
    cout << deck[target[i]] << " ";
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solution();

  return 0;
}