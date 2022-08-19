/*
 * @Descroption: LeetCode 1975. 最大方阵和
 * @Author: EmoryHuang
 * @Date: 2021-09-23 19:26:47
 * @Method:
 * 如果负数的数量是偶数，那么所有负数都能变成正数
 * 如果负数的数量是奇数，那么只需要记录绝对值最小的数
 */

class Solution {
   public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long ans = 0;
        // 记录负数的数量，绝对值最小的数
        int cnt = 0, m = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans += abs(matrix[i][j]);
                if (matrix[i][j] <= 0) cnt++;
                m = min(m, abs(matrix[i][j]));
            }
        }
        if (cnt % 2 == 0) return ans;
        return ans - 2 * m;
    }
};