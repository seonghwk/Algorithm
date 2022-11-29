#include <iostream>

using namespace std;

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    string str;
    cin >> str;
    cout << str[0] << str[str.length() - 1] << "\n";
  }
  return 0;
}