/*
 * @Descroption: LeetCode 807. 保持城市天际线
 * @Author: EmoryHuang
 * @Date: 2021-06-19 14:47:00
 * @解题思路:
 * 求出行列的最大值元素，对于每个grid[i][j]只需要取所在行列最大值的最小值即可
 */

class Solution {
   public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> row(n), col(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                row[i] = max(row[i], grid[i][j]);
                col[j] = max(col[j], grid[i][j]);
            }
        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                ans += min(row[i], col[j]) - grid[i][j];
            }
        return ans;
    }
};