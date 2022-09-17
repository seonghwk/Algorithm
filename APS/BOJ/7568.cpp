//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//struct Dungchi {
//	int id;
//	int weight;
//	int height;
//};
//
//struct cmp {
//	bool operator()(Dungchi a, Dungchi b) {
//		if (a.weight > b.weight && a.height > b.height)
//			return false;
//		if (a.weight < b.weight && a.height < b.height)
//			return true;
//		return false;
//	}
//};
//
//int n;
//int result[50];
//priority_queue<Dungchi, vector<Dungchi>, cmp> pq;
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		int x, y;
//		cin >> x >> y;
//		pq.push({ i,x,y });
//	}
//
//	Dungchi prev = pq.top();
//	int rank = 1;
//	int cnt = 0;
//	while (!pq.empty()) {
//		Dungchi now = pq.top();
//		pq.pop();
//
//		cnt++;
//
//		if (prev.weight > now.weight && prev.height> now.height) {
//			rank = cnt;
//		}
//
//		result[now.id] = rank;
//
//		prev = now;
//	}
//
//	for (int i = 0; i < n; i++) {
//		cout << result[i] << " ";
//	}
//
//	return 0;
//}