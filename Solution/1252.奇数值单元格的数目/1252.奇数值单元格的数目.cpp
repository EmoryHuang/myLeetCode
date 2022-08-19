/*
 * @Descroption: LeetCode 1252. 奇数值单元格的数目
 * @Author: EmoryHuang
 * @Date: 2021-07-15 20:09:02
 * @解题思路:
 * 模拟法，模拟对每行每列的加法，然后遍历统计奇数的个数
 */

class Solution {
   public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<vector<int>> mat(m, vector<int>(n));
        for (auto ind : indices) {
            int row = ind[0], col = ind[1];
            for (int i = 0; i < n; i++) mat[row][i]++;
            for (int i = 0; i < m; i++) mat[i][col]++;
        }
        int ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (mat[i][j] % 2 == 1) ans++;
        return ans;
    }
};