//#include <iostream>
//
//using namespace std;
//
//int fastSum(int n) {
//	if (n == 1)
//		return 1;
//	if (n % 2 == 1)
//		return fastSum(n - 1) + n;
//	return 2 * fastSum(n / 2) + (n / 2) * (n / 2);
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	cout << fastSum(10) << "\n";
//
//	return 0;
//}