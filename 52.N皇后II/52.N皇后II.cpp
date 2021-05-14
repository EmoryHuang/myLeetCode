/*
 * @Descroption: LeetCode 52. N 皇后 II
 * @Author: EmoryHuang
 * @Date: 2021-05-11 16:50:36
 * @解题思路:
 * 为了判断一个位置所在的列和两条斜线上是否已经有皇后，使用三个集合col,diag,undiag分别记录每一列以及两个方向的每条斜线上是否有皇后。
 * 使用行下标与列下标之差即可明确表示每一条对角线的斜线。
 * 使用行下标与列下标之和即可明确表示每一条反对角线的斜线。
 * 每次放置皇后时，对于每个位置判断其是否在三个集合中，如果三个集合都不包含当前位置，则当前位置是可以放置皇后的位置。
 */

class Solution {
   public:
    int ans = 0;
    void dfs(int n, int row, vector<bool>& col, vector<bool>& diag, vector<bool>& undiag) {
        if (row == n) {  // 方案可行
            ans++;
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!col[i] && !diag[row - i + n - 1] && !undiag[row + i]) {
                col[i] = true;
                diag[row - i + n - 1] = true;
                undiag[row + i] = true;
                dfs(n, row + 1, col, diag, undiag);  // 递归
                col[i] = false;                      // 回溯
                diag[row - i + n - 1] = false;
                undiag[row + i] = false;
            }
        }
    }
    int totalNQueens(int n) {
        // col diag undiag 分别表示列，对角线，反对角线上是否有皇后
        vector<bool> col(n), diag(n), undiag(n);
        dfs(n, 0, col, diag, undiag);
        return ans;
    }
};