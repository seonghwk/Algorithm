#include <iostream>
#include <vector>

using namespace std;

struct Node {
  int y, x;
};

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};

int R, C;
vector<vector<char>> board;
void input() {
  cin >> R >> C;
  board = vector<vector<char>>(R, vector<char>(C));
  string row;
  for (int i = 0; i < R; i++) {
    cin >> row;
    for (int j = 0; j < C; j++) {
      board[i][j] = row[j];
    }
  }
}

int cnt_max = 0;

void dfs(Node now, vector<int>& DAT, int cnt) {
  cnt_max = max(cnt_max, cnt);
  // recursive case
  for (int dir = 0; dir < 4; dir++) {
    int ny = now.y + dy[dir];
    int nx = now.x + dx[dir];
    if (!(0 <= ny && ny < R) || !(0 <= nx && nx < C)) continue;
    if (DAT[board[ny][nx]] != 0) continue;
    DAT[board[ny][nx]]++;
    dfs({ny, nx}, DAT, cnt + 1);
    DAT[board[ny][nx]]--;
  }
}

void solve() {
  vector<int> DAT('Z' - 'A' + 1);
  DAT[board[0][0]]++;
  dfs({0, 0}, DAT, 1);
  cout << cnt_max;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}