/*
 * @Descroption: LeetCode 1380. �����е�������
 * @Author: EmoryHuang
 * @Date: 2021-08-20 19:20:03
 * @Method:
 * ���������ҵ�ÿ�е���Сֵ��ÿ�е����ֵ
 * Ȼ���ٴα������жϵ�ǰԪ���Ƿ��ǵ�ǰ�е���Сֵ���е����ֵ
 */

class Solution {
   public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> row(m, INT_MAX), col(n), ans;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                row[i] = min(row[i], matrix[i][j]);
                col[j] = max(col[j], matrix[i][j]);
            }
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] == row[i] && matrix[i][j] == col[j]) ans.push_back(matrix[i][j]);
        return ans;
    }
};