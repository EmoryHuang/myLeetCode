/*
 * @Descroption: LeetCode 1351. 统计有序矩阵中的负数
 * @Author: EmoryHuang
 * @Date: 2021-06-22 19:32:00
 * @解题思路:
 * 若当前数为负数，那么剩下的数必然也是负数，计数后进入下一行
 */

class Solution {
   public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] < 0) {
                    cnt += n - j;
                    break;
                }
        return cnt;
    }
};