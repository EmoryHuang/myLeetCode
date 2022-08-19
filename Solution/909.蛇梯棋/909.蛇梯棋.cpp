/*
 * @Descroption: LeetCode 909. ������
 * @Author: EmoryHuang
 * @Date: 2021-06-27 14:29:00
 * @����˼·:
 * BFS
 * ÿ�ο��ƶ��ķ�ΧΪ 6�����й�����ȱ������õ� next
 * �� next Ϊ�߻����ӣ���ô���� next
 */

class Solution {
   public:
    vector<int> change(int pos, int n) {
        int row, col;
        row = (pos - 1) / n;
        col = (pos - 1) % n;
        if (row % 2 == 1) col = n - 1 - col;
        return {n - 1 - row, col};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        queue<pair<int, int>> q;  // ��¼Ԫ���Լ��������Ҫ�Ĵ���
        set<int> vis;             // ��¼Ԫ���Ƿ����
        q.push({1, 0});
        vis.insert(1);
        while (!q.empty()) {
            auto [cur, step] = q.front();
            q.pop();
            if (cur == n * n) return step;
            for (int i = 1; i <= 6; i++) {
                int next = cur + i;
                if (next > n * n) break;
                auto rc = change(next, n);
                if (board[rc[0]][rc[1]] > 0) next = board[rc[0]][rc[1]];
                if (vis.count(next) == 0) {
                    vis.insert(next);
                    q.push({next, step + 1});
                }
            }
        }
        return -1;
    }
};