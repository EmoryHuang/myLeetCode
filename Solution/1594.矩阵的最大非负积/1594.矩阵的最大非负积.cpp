/*
 * @Descroption: LeetCode 1594. 矩阵的最大非负积
 * @Author: EmoryHuang
 * @Date: 2021-06-20 13:46:00
 * @解题思路:
 * 动态规划
 * 在 dp 时需要考虑数组元素的正负问题
 * 因此，同时维护两个矩阵 maxpos 和 minneg, 分别存储最大正值和最小负值
 * 状态转移方程
 * 若 grid[i][j] >= 0，则
 * maxpos[i][j] = grid[i][j] * max(maxpos[i][j - 1], maxpos[i - 1][j])
 * minneg[i][j] = grid[i][j] * min(minneg[i][j - 1], minneg[i - 1][j])
 * 若 grid[i][j] < 0，则
 * maxpos[i][j] = grid[i][j] * min(minneg[i][j - 1], minneg[i - 1][j])
 * minneg[i][j] = grid[i][j] * max(maxpos[i][j - 1], maxpos[i - 1][j])
 */

class Solution {
   public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<long>> maxpos(m, vector<long>(n));  //存储最大正值
        vector<vector<long>> minneg(m, vector<long>(n));   //存储最小负值
        // 初始化第一行和第一列
        maxpos[0][0] = minneg[0][0] = grid[0][0];
        for (int i = 1; i < m; i++) maxpos[i][0] = minneg[i][0] = maxpos[i - 1][0] * grid[i][0];
        for (int i = 1; i < n; i++) maxpos[0][i] = minneg[0][i] = maxpos[0][i - 1] * grid[0][i];
        // 状态转移
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++) {
                if (grid[i][j] >= 0) {
                    maxpos[i][j] = grid[i][j] * max(maxpos[i][j - 1], maxpos[i - 1][j]);
                    minneg[i][j] = grid[i][j] * min(minneg[i][j - 1], minneg[i - 1][j]);
                } else {
                    maxpos[i][j] = grid[i][j] * min(minneg[i][j - 1], minneg[i - 1][j]);
                    minneg[i][j] = grid[i][j] * max(maxpos[i][j - 1], maxpos[i - 1][j]);
                }
            }
        if (maxpos[m - 1][n - 1] < 0) return -1;
        return maxpos[m - 1][n - 1] % 1000000007;
    }
};