#include <iostream>

using namespace std;

int ft_factorial(int num) {
  // base case
  if (num <= 1) return 1;
  // recursive case
  return num * ft_factorial(num - 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;
  cout << ft_factorial(N);

  return 0;
}