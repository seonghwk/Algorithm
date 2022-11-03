#include <iostream>
#include <vector>

using namespace std;

struct Info {
	int p, f, s, v, c;
};

int N;
Info m;
vector<Info> v;
vector<int> path;
int min_cost;
vector<int> min_path;

bool isValid(Info cur) {
	if (m.p > cur.p)
		return false;
	if (m.f > cur.f)
		return false;
	if (m.s > cur.s)
		return false;
	if (m.v > cur.v)
		return false;
	return true;
}

void dfs(Info cur, int now_id) {
	// base case
	if (min_cost <= cur.c)
		// �̹� �����ϴ� ��찡 �ִµ�, �̶��� �ּҺ�뺸�� ũ�� return
		return;
	if (isValid(cur)) {
		// ���ݱ����� ���� ������ ��ȿ�ϸ�, �� ������ �ʿ� ����.
		// �ּ� ��뺸�� ���� ����̹Ƿ� �����Ѵ�.
		min_cost = cur.c;
		min_path = path;
		return;
	}
	// recursive case
	for (int i = now_id; i < N; i++) {
		// �̱� �����ؾ��� id���� �����ϱ�
		// ���ݱ��� ���� ����ѰͿ� ������ ����� ���� next�� ����
		// ������ ���� ���� ���� ���� �� ��������
		Info next = cur;
		next.p += v[i].p;
		next.f += v[i].f;
		next.s += v[i].s;
		next.v += v[i].v;
		next.c += v[i].c;
		path.push_back(i);
		dfs(next, i + 1);
		path.pop_back();
	}
}

void solution() {
	dfs({}, 0);
	if (min_cost == 2147483647) {
		cout << -1;
		return;
	}
	cout << min_cost << "\n";
	for (int i = 0; i < min_path.size(); i++) {
		// ����� 0-indexing���� ������, ����� 1-indexing
		cout << min_path[i] + 1 << " ";
	}
}

void input() {
	min_cost = 2147483647;

	cin >> N;
	cin >> m.p >> m.f >> m.s >> m.v;
	for (int i = 0; i < N; i++) {
		Info t;
		cin >> t.p >> t.f >> t.s >> t.v >> t.c;
		v.push_back(t);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}

/*
����� N ���� ����
����� ���� �̻� �ǵ���
���� ������Ű�鼭 ��� �ּ�
���� ����� ���� �����ϴ� �ּ� ���

*/