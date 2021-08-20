/*
 * @Descroption: LeetCode 1380. 矩阵中的幸运数
 * @Author: EmoryHuang
 * @Date: 2021-08-20 19:20:03
 * @Method:
 * 遍历矩阵，找到每行的最小值和每列的最大值
 * 然后再次遍历，判断当前元素是否是当前行的最小值和列的最大值
 */

class Solution {
   public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> row(m, INT_MAX), col(n), ans;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                row[i] = min(row[i], matrix[i][j]);
                col[j] = max(col[j], matrix[i][j]);
            }
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] == row[i] && matrix[i][j] == col[j]) ans.push_back(matrix[i][j]);
        return ans;
    }
};