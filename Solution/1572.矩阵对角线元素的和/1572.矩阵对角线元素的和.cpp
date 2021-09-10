/*
 * @Descroption: LeetCode 1572. 矩阵对角线元素的和
 * @Author: EmoryHuang
 * @Date: 2021-08-14 14:19:53
 * @Method:
 * 因为是正方形矩阵，所以可以直接得到四个位置的值，遍历一遍即可
 * 若为中心元素，只需要加一次
 */

class Solution {
   public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (i == n - i - 1)
                ans += mat[i][i];
            else
                ans += mat[i][i] + mat[i][n - i - 1];
        }
        return ans;
    }
};