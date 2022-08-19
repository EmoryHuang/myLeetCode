/*
 * @Descroption: 面试题 10.09. 排序矩阵查找
 * @Author: EmoryHuang
 * @Date: 2021-07-18 14:11:38
 * @解题思路:
 * 从左下或者右上开始查找
 */

class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return false;
        int m = matrix.size(), n = matrix[0].size();
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