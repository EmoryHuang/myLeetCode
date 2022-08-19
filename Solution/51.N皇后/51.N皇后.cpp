/*
 * @Descroption: LeetCode 51. N 皇后
 * @Author: EmoryHuang
 * @Date: 2021-05-11 17:40:36
 * @解题思路: 在 LeetCode 52. N 皇后 II 的基础上改进即可，记录每种解法的皇后位置，生成棋盘
 * 为了判断一个位置所在的列和两条斜线上是否已经有皇后，使用三个集合col,diag,undiag分别记录每一列以及两个方向的每条斜线上是否有皇后。
 * 使用行下标与列下标之差即可明确表示每一条对角线的斜线。
 * 使用行下标与列下标之和即可明确表示每一条反对角线的斜线。
 * 每次放置皇后时，对于每个位置判断其是否在三个集合中，如果三个集合都不包含当前位置，则当前位置是可以放置皇后的位置。
 */

class Solution {
   public:
    void dfs(vector<vector<string>>& solutions, vector<int>& queens, int n, int row,
             vector<bool>& col, vector<bool>& diag, vector<bool>& undiag) {
        if (row == n) {            // 方案可行
            vector<string> board;  // 生成棋盘
            for (int i = 0; i < n; i++) {
                string line = string(n, '.');
                line[queens[i]] = 'Q';
                board.push_back(line);
            }
            solutions.push_back(board);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!col[i] && !diag[row - i + n - 1] && !undiag[row + i]) {
                queens[row] = i;
                col[i] = true;
                diag[row - i + n - 1] = true;
                undiag[row + i] = true;
                dfs(solutions, queens, n, row + 1, col, diag, undiag);  // 递归
                queens[row] = -1;                                       // 回溯
                col[i] = false;
                diag[row - i + n - 1] = false;
                undiag[row + i] = false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        // col diag undiag 分别表示列，对角线，反对角线上是否有皇后
        vector<bool> col(n), diag(n), undiag(n);
        vector<vector<string>> solutions;  // 记录解法
        vector<int> queens(n, -1);         // 记录皇后位置
        dfs(solutions, queens, n, 0, col, diag, undiag);
        return solutions;
    }
};