/*
 * @Descroption: LeetCode 48. 旋转图像
 * @Author: EmoryHuang
 * @Date: 2021-05-21 15:33:00
 * @解题思路:
 * 先转置，再水平翻转
 */

class Solution {
   public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // 矩阵转置
        for (int i = 0; i < n; i++)
            for (int j = 0; j < i; j++) 
                swap(matrix[i][j], matrix[j][i]);
        // 水平翻转
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n / 2; j++) 
                swap(matrix[i][j], matrix[i][n - 1 - j]);
    }
};