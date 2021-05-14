/*
 * @Descroption: LeetCode 73. 矩阵置零
 * @Author: EmoryHuang
 * @Date:  2021-03-21 19:30:36
 * @解题思路:
 * 方法一：空间复杂度 O(mn)
 * 空间复杂度 O(mn)的方法很容易想到，就是再建立两个数组对元素进行标记，
 * 如果某个元素为 `0`，那么就将该元素所在的行和列所对应标记数组的位置置为 `true`
 *
 * 方法二：空间复杂度 O(1)
 * 用矩阵的第一行和第一列代替方法一中的两个标记数组，但这样会导致原数组的第一行和第一列被修改，
 * 因此使用两个标记变量，分别记录第一行和第一列是否原本包含 `0`
 */

class Solution {
   public:
    // 方法一：空间复杂度O(mn)
    // void setZeroes(vector<vector<int>>& matrix) {
    //     int m = matrix.size();
    //     int n = matrix[0].size();
    //     vector<bool> row(m), col(n);
    //     for (int i = 0; i < m; i++) {
    //         for (int j = 0; j < n; j++) {
    //             if (!matrix[i][j]) {
    //                 row[i] = col[j] = true;
    //             }
    //         }
    //     }
    //     for (int i = 0; i < m; i++) {
    //         for (int j = 0; j < n; j++) {
    //             if (row[i] || col[j]) {
    //                 matrix[i][j] = 0;
    //             }
    //         }
    //     }
    // }

    // 方法二：空间复杂度O(1)
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool flagRow = false, flagCol = false;
        //判断第一列是否有0
        for (int i = 0; i < m; i++) {
            if (!matrix[i][0]) {
                flagCol = true;
                break;
            }
        }
        //判断第一行是否有0
        for (int i = 0; i < n; i++) {
            if (!matrix[0][i]) {
                flagRow = true;
                break;
            }
        }
        // 遍历除了第一行第一列的元素，若为0，则置对应第一行第一列的元素为0
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (!matrix[i][j]) {
                    matrix[0][j] = matrix[i][0] = 0;
                }
            }
        }
        // 遍历第一行第一列的元素，若为0，则置整行整列为0
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (!matrix[0][j] || !matrix[i][0]) {
                    matrix[i][j] = 0;
                }
            }
        }
        //若第一行有0
        if (flagRow) {
            for (int i = 0; i < n; i++) {
                matrix[0][i] = 0;
            }
        }
        //若第一列有0
        if (flagCol) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};