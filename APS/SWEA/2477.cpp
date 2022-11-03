#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Desk {
	int id;
	int time_open;
	int time_consume;
};

struct Guest {
	int id;
	int time_visit;
	int reception;
	int repair;
};

struct cmp_desk {
	bool operator()(Desk a, Desk b) {
		if (a.time_open < b.time_open)
			return false;
		if (a.time_open > b.time_open)
			return true;
		if (a.id < b.id)
			return false;
		if (a.id > b.id)
			return true;
		return false;
	}
};

struct cmp_guest {
	bool operator()(Guest a, Guest b) {
		if (a.time_visit < b.time_visit)
			return false;
		if (a.time_visit > b.time_visit)
			return true;
		if (a.reception < b.reception)
			return false;
		if (a.reception > b.reception)
			return true;
		if (a.id < b.id)
			return false;
		if (a.id > b.id)
			return true;
		return false;
	}
};

int N, M, K, A, B;

priority_queue<Desk, vector<Desk>, cmp_desk> pq_reception;
priority_queue<Desk, vector<Desk>, cmp_desk> pq_repair;
priority_queue<Guest, vector<Guest>, cmp_guest> pq_guest;
vector<int> v;

int solution() {
	while (!pq_guest.empty()) {
		Guest now = pq_guest.top();
		pq_guest.pop();

		if (now.reception == 0) {
			Desk desk = pq_reception.top();
			pq_reception.pop();

			now.reception = desk.id;
			desk.time_open = max(now.time_visit, desk.time_open) + desk.time_consume;
			now.time_visit = desk.time_open;

			pq_reception.push(desk);
			pq_guest.push(now);
			continue;
		}
		if (now.repair == 0) {
			Desk desk = pq_repair.top();
			pq_repair.pop();

			now.repair = desk.id;
			desk.time_open = max(now.time_visit, desk.time_open) + desk.time_consume;
			now.time_visit = desk.time_open;

			pq_repair.push(desk);

			if (now.reception == A && now.repair == B)
				v.push_back(now.id);

			continue;
		}
	}
	if (v.empty())
		return -1;
	int ret = 0;
	for (int i = 0; i < v.size(); i++)
		ret += v[i];
	return ret;
}

void input() {

	v.clear();
	pq_reception = priority_queue<Desk, vector<Desk>, cmp_desk> ();
	pq_repair = priority_queue<Desk, vector<Desk>, cmp_desk> ();

	cin >> N >> M >> K >> A >> B;
	for (int i = 1; i <= N; i++) {
		Desk now = {i, 0, 0};
		cin >> now.time_consume;
		pq_reception.push(now);
	}

	for (int i = 1; i <= M; i++) {
		Desk now = { i, 0, 0 };
		cin >> now.time_consume;
		pq_repair.push(now);
	}

	for (int i = 1; i <= K; i++) {
		Guest now = { i, 0, 0, 0 };
		cin >> now.time_visit;
		pq_guest.push(now);
	}
}

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		input();
		cout << "#" << tc << " " << solution() << "\n";
	}

}

/*
* 1-indexing
* 
고객이 언제 방문했는가를 고객 만족도 설문지로 알고자 한다.
N개의 접수창구, M개의 정비 창구

접수 창구에서 고장 접수
정비 창구에서 차량 정비
차량 정비 후 고객만족도 설문

담당자 업무 능력따라 처리 시간 다르다

K명 이용
고객번호 1번부터
도착시간은 t
빈 접수 창구 있으면 고장 접수
없으면 기다린다.
고객번호 낮으면 우선, 접수 창구 낮은게 우선
고객번호, 접수창구 번호

빈 정비 창구 있으면 차량 정비
없으면 기다린다.
먼저 기다린 사람 우선
접수 창구 번호가 작은 고객이 우선
시간, 접수창구(출신), 정비창구 번호

손님 오는 시간
접수 가능한 창구 뽑아서
*/