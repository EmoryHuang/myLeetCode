/*
 * @Descroption: LeetCode 240. ������ά���� II
 * @Author: EmoryHuang
 * @Date: 2021-05-28 13:37:17
 * @����˼·:
 * �����½ǣ������Ͻǣ���ʼ����
 * ����ǰ�����Ԫ��ֵ > target���������ƶ�һ���в���
 * ����ǰ�����Ԫ��ֵ < target���������ƶ�һ���в���
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