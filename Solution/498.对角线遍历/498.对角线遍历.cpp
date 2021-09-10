/*
 * @Descroption: LeetCode 498. 对角线遍历
 * @Author: EmoryHuang
 * @Date: 2021-08-12 19:42:58
 * @Method:
 * 模拟
 * 判断当前对角线的层数，然后从左下到右上或者从右上到左下
 */

class Solution {
   public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        if (mat.size() == 0) return ans;
        int m = mat.size(), n = mat[0].size();
        int row = 0, col = 0;
        for (int i = 0; i < m * n; i++) {
            ans.push_back(mat[row][col]);
            if ((row + col) % 2 == 0) {
                if (col == n - 1)  // 最后一列
                    row += 1;
                else if (row == 0)  // 第一行
                    col += 1;
                else  // 左下到右上
                    row--, col++;
            } else {
                if (row == m - 1)  // 最后一列
                    col += 1;
                else if (col == 0)  // 第一行
                    row += 1;
                else  // 左下到右上
                    row++, col--;
            }
        }
        return ans;
    }
};