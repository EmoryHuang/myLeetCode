/*
 * @Descroption: LeetCode 面试题 01.08. 零矩阵
 * @Author: EmoryHuang
 * @Date: 2022-09-30 09:08:55
 * @Method:
 * 寻找矩阵中所有零所在的位置，并记录，之后再次遍历清零
 */

class Solution {
    public void setZeroes(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        int[] row = new int[m], col = new int[n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (row[i] == 1 || col[j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
}