#include <iostream>
#include <vector>

using namespace std;

const int coverType[4][3][2] = {
    {{0, 0}, {1, 0}, {0, 1}},
    {{0, 0}, {0, 1}, {1, 1}},
    {{0, 0}, {1, 0}, {1, 1}},
    {{0, 0}, {1, 0}, {1, -1}},
};

bool set(vector<vector<int>> &board, int y, int x, int type, int delta){
    bool ok = true;
    // �ش� type���� �� ĭ ��� ���� �� �ִ��� Ȯ��
    for(int i =0; i < 3; i++){
        const int ny = y + coverType[type][i][0];
        const int nx = x + coverType[type][i][1];
        // ���� ����� �� ���´�
        if (!(0 <= ny && ny < board.size() && 0 <= nx && nx < board[0].size()))
            ok = false;
        // delta : 1 -> ����
        // delta : -1 -> ġ���
        else if ((board[ny][nx] += delta) > 1)
            ok = false;
    }
    return ok;
}

int cover(vector<vector<int>>& board){
    // ���������� �о� �������� ����ִ� ĭ ã��
    int y = -1, x = -1;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == 0){
                // ����ִ� ĭ ã�Ҵ�
                y = i;
                x = j;
                break;
            }
        }
        if (y != -1)
            break;
    }
    // base case
    // �� �ѷ��ôµ� ��ĭ�� ���� -> �� ä���� ��
    if (y == -1)
        return 1;
    // recursive case
    int ret = 0;
    for (int type = 0; type < 4; type++){
        // �ش� type���� �� ��ġ�� ���� ����, ���� �� �ִ°�?
        if (set(board, y, x, type, 1))
            // �� �� �����ϱ�, �̷��� ������ �� ������ ����� �� add
            ret += cover(board);
        // ����
        set(board, y, x, type, -1);
    }
    return ret;
}

vector<vector<int>> input() {
    vector<vector<int>> board;
    int H, W;
    cin >> H >> W;
    for (int i = 0; i < H; i++) {
        vector<int> row;
        for (int j = 0; j < W; j++) {
            char ch;
            cin >> ch;
            if (ch == '#')
                row.push_back(1);
            else if (ch == '.')
                row.push_back(0);
        }
        board.push_back(row);
    }
    return board;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int C;
    cin >> C;
    for (int tc = 1; tc <= C; tc++){
        vector<vector<int>> board = input();
        cout << cover(board) << "\n";
    }

	return 0;
}