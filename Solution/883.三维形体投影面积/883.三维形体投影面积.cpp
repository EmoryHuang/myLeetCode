/*
 * @Descroption: LeetCode 883. 三维形体投影面积
 * @Author: EmoryHuang
 * @Date: 2021-04-16 19:24:36
 * @解题思路:
 * 非零元素个数 + 矩阵每行的最大值 + 矩阵每列的最大值
 */

class Solution {
   public:
    int projectionArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        int maxr = 0;
        vector<int> maxc(n);
        for (int i = 0; i < m; i++) {
            maxr = 0;
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) ans++;               // 顶部
                maxr = max(maxr, grid[i][j]);        // 行最大值
                maxc[j] = max(maxc[j], grid[i][j]);  // 列最大值向量
            }
            ans += maxr;
        }
        for (int i = 0; i < n; i++) ans += maxc[i];
        return ans;
    }
};