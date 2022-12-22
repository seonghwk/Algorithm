#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> board;

void input() {
  cin >> n >> m;
  int len = pow(2, ceil(log2(max(n, m))));
  board.resize(len, vector<int>(len));
  string row;
  for (int i = 0; i < n; i++) {
    cin >> row;
    for (int j = 0; j < m; j++) {
      board[i][j] = row[j] - '0';
    }
  }
}

void solve() {}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}

/*
쿼드트리
하나의 색깔이면 하나의 노드로
그렇지 않으면 그림을 넷으로 나누고
나누어진 그림을 4개의 노드로 표현

크기가 2의 k승이 아니면 나머지 공간은 흰색으로 채운다

*/