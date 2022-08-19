/*
 * @Descroption: LeetCode 909. 蛇梯棋
 * @Author: EmoryHuang
 * @Date: 2021-06-27 14:29:00
 * @解题思路:
 * BFS
 * 每次可移动的范围为 6，进行广度优先遍历，得到 next
 * 若 next 为蛇或梯子，那么更新 next
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
        queue<pair<int, int>> q;  // 记录元素以及到达的需要的次数
        set<int> vis;             // 记录元素是否访问
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