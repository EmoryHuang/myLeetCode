/*
 * @Descroption: LeetCode 240. 搜索二维矩阵 II
 * @Author: EmoryHuang
 * @Date: 2021-05-28 13:37:17
 * @解题思路:
 * 从左下角（或右上角）开始查找
 * 若当前矩阵的元素值 > target，则向上移动一行列不变
 * 若当前矩阵的元素值 < target，则向右移动一列行不变
 */

class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i = m - 1, j = 0;
        while (i >= 0 && j < n) {
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] > target)
                i--;
            else
                j++;
        }
        return false;
    }
};