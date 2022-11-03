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
���� ���� �湮�ߴ°��� �� ������ �������� �˰��� �Ѵ�.
N���� ����â��, M���� ���� â��

���� â������ ���� ����
���� â������ ���� ����
���� ���� �� �������� ����

����� ���� �ɷµ��� ó�� �ð� �ٸ���

K�� �̿�
����ȣ 1������
�����ð��� t
�� ���� â�� ������ ���� ����
������ ��ٸ���.
����ȣ ������ �켱, ���� â�� ������ �켱
����ȣ, ����â�� ��ȣ

�� ���� â�� ������ ���� ����
������ ��ٸ���.
���� ��ٸ� ��� �켱
���� â�� ��ȣ�� ���� ���� �켱
�ð�, ����â��(���), ����â�� ��ȣ

�մ� ���� �ð�
���� ������ â�� �̾Ƽ�
*/