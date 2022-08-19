/*
 * @Descroption: LeetCode 766. 托普利茨矩阵
 * @Author: EmoryHuang
 * @Date: 2021-08-24 11:21:44
 * @Method:
 * 比较当前位置元素和它的右下方元素是否相等
 */

class Solution {
   public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size() - 1; ++i) {
            for (int j = 0; j < matrix[0].size() - 1; ++j) {
                if (matrix[i][j] != matrix[i + 1][j + 1]) return false;
            }
        }
        return true;
    }
};