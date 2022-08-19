/*
 * @Descroption: LeetCode 48. ��תͼ��
 * @Author: EmoryHuang
 * @Date: 2021-05-21 15:33:00
 * @����˼·:
 * ��ת�ã���ˮƽ��ת
 */

class Solution {
   public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // ����ת��
        for (int i = 0; i < n; i++)
            for (int j = 0; j < i; j++) 
                swap(matrix[i][j], matrix[j][i]);
        // ˮƽ��ת
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n / 2; j++) 
                swap(matrix[i][j], matrix[i][n - 1 - j]);
    }
};