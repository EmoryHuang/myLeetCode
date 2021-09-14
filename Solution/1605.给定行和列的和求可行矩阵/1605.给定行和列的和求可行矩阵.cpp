/*
 * @Descroption: LeetCode 1605. 给定行和列的和求可行矩阵
 * @Author: EmoryHuang
 * @Date: 2021-09-14 16:11:05
 * @Method:
 * 贪心
 * 使用 rowCur, colCur 分别记录当前每行每列的和
 * 对于每个位置，取行列当前最大可以填充的数的较小值
 */

class Solution {
   public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int row = rowSum.size(), col = colSum.size();
        // rowCur, colCur 分别记录当前每行每列的和
        vector<int> rowCur(row), colCur(col);
        vector<vector<int>> ans(row, vector<int>(col));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                // 取行列当前最大可以填充的数的较小值
                int num = min(rowSum[i] - rowCur[i], colSum[j] - colCur[j]);
                ans[i][j] = num;
                rowCur[i] += num;
                colCur[j] += num;
            }
        }
        return ans;
    }
};