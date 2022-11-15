#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> v;

void input() {
  cin >> N >> M;
  v = vector<int>(N);
  for (int i = 0; i < N; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
}

void solution() {}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solution();

  return 0;
}

/*
M미터 필요
목재절단기 높이 H 지정
한 줄에 연속해있는 나무 모두 절단
H보다 크면 H로 잘린다, 낮은 나무는 안잘린다.
잘린 부분을 들고간다.
*/