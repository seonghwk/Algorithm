#include <iostream>
#include <queue>
#include <vector>

using namespace std;

string str;

void input() { cin >> str; }

queue<int> split() {
  queue<int> q;
  int a = 0, b = 0, flag = 0;
  int num;
  while (true) {
    while (!(str[b] == '+' || str[b] == '-' || str[b] == '\0')) b++;
    num = stoi(str.substr(a, b - a));
    if (flag == 1)
      q.back() += num;
    else
      q.push(num);
    a = b + 1;
    if (str[b] == '+')
      flag = 1;
    else
      flag = 0;
    if (str[b] == '\0') break;
    b = a;
  }
  return q;
}

void solve() {
  queue<int> q = split();
  int ret = q.front();
  q.pop();
  while (!q.empty()) {
    ret -= q.front();
    q.pop();
  }
  cout << ret;
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
괄호를 쳐서 식의 값을 최소로 만들기
1. 숫자와 기호 parsing
2. 덧셈만 합친다.
3. 합친 후 수식 계산
*/
