/*
 * @Descroption: LeetCode 766. �������ľ���
 * @Author: EmoryHuang
 * @Date: 2021-08-24 11:21:44
 * @Method:
 * �Ƚϵ�ǰλ��Ԫ�غ��������·�Ԫ���Ƿ����
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