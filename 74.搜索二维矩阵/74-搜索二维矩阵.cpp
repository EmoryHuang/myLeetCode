/*
 * @Descroption: LeetCode 74. 搜索二维矩阵
 * @Author: EmoryHuang
 * @Date: 2021-03-24 15:30:36
 * @解题思路:
 * 方法一：左下或右上开始
 * 在递增的二维矩阵中寻找元素，应该很容易可以想到，相比于从左上或者右下开始寻找，左下或右上开始的效果明显更好，一次可以排除一行
 *
 * 方法二：二分
 * 更多有关二分查找的探究可以看：[二分查找学习笔记](https://emoryhuang.github.io/blog/158595231.html)
 */

class Solution {
   public:
    // 方法一：左下或右上开始
    // bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //     int m = matrix.size();
    //     int n = matrix[0].size();
    //     int i = m - 1, j = 0;
    //     while (i >= 0 && j < n) {
    //         if (matrix[i][j] == target)
    //             return true;
    //         else if (matrix[i][j] > target)
    //             i--;
    //         else
    //             j++;
    //     }
    //     return false;
    // }

    // 方法二：二分
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0, r = m * n - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (target == matrix[mid / n][mid % n])
                return true;
            else if (target > matrix[mid / n][mid % n])
                l = mid + 1;
            else
                r = mid - 1;
        }
        return false;
    }
};