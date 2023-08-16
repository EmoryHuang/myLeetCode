/*
 * @Description: LeetCode 240. 搜索二维矩阵 II
 * @Author: EmoryHuang
 * @Date: 2023-08-04 15:12:33
 * @Method:
 * 从右上角开始搜索
 */

import java.util.*;

class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length, n = matrix[0].length;
        int x = 0, y = n - 1;
        while (x < m && y >= 0) {
            if (matrix[x][y] == target) {
                return true;
            } else if (matrix[x][y] > target) {
                y--;
            } else {
                x++;
            }
        }
        return false;
    }
}