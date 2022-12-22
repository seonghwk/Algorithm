#include <iostream>

using namespace std;

int N;
void input() {
  cin >> N;
  float optimal_ratio = 0.0;
  int optimal_price = 2147483637;
  float weight;
  int price;
  for (int i = 0; i < N; i++) {
    cin >> weight >> price;
    if ((weight / price) == optimal_ratio) {
      optimal_price = min(price, optimal_price);
    } else if ((weight / price) > optimal_ratio) {
      optimal_ratio = weight / price;
      optimal_price = price;
    }
  }
  cout << optimal_price << "\n";
}

void solve() { return; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;
  for (int tc = 1; tc <= T; tc++) {
    input();
    solve();
  }

  return 0;
}

/*
같은 가격으로 살수 있는 최대 중량이 큰 맛살 선택
중량 / 가격이 큰 것
*/