#include <limits.h>

#include <iostream>
#include <vector>

using namespace std;

int N;
string status, target;
int min_cnt = INT_MAX;

void input() {
  cin >> N;
  cin >> status;
  cin >> target;
}

void toggle(int idx) {
  if (status[idx] == '0')
    status[idx] = '1';
  else
    status[idx] = '0';
}

void push(int idx) {
  toggle(idx);
  if (idx != 0) toggle(idx - 1);
  if (idx != N - 1) toggle(idx + 1);
}

void dfs(int start, int cnt) {
  // base case
  if (start == N) return;
  if (min_cnt < cnt) return;
  if (status == target) {
    min_cnt = cnt;
    return;
  }
  // recursive case
  for (int i = start; i < N; i++) {
    push(i);
    dfs(i + 1, cnt + 1);
    push(i);
    dfs(i + 1, cnt);
  }
}

void solve() {
  dfs(0, 0);
  if (min_cnt == INT_MAX) min_cnt = -1;
  cout << min_cnt;
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
N개의 스위치, N개의 전구
전구는 On or Off
i번 누르면 i-1, i, i+1 세 개의 전구 상태 바뀐다

스위치를 최소 몇번 누르면 되는가?
*/