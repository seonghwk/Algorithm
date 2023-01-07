#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
int DAT[20'001];
vector<int> arr;

void input() {
  cin >> N;
  arr.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
    DAT[arr[i] + 10'000]++;
  }
  int cnt = 0;
  for (int i = 0; i < N; i++) {
  }
}

void solve() {
  sort(arr.begin(), arr.end());
  long long cnt = 0;
  int target;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      target = (arr[i] + arr[j]) * -1;

      if (!(-10'000 <= target && target <= 10'000)) continue;

      DAT[arr[i] + 10'000]--;
      DAT[arr[j] + 10'000]--;

      cnt += DAT[target + 10'000];

      DAT[arr[i] + 10'000]++;
      DAT[arr[j] + 10'000]++;
    }
  }
  cout << cnt / 3;
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
3명으로 구성된 팀
코딩실력과 팀워크

코딩실력은 -10'000 ~ 10'000
코딩 실력 합 0이 되도록
얼마나 많은 경우의 수
*/