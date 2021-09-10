/*
 * @Descroption: LeetCode 1582. �����ƾ����е�����λ��
 * @Author: EmoryHuang
 * @Date: 2021-06-20 16:06:00
 * @����˼·:
 * ��������������ÿ��ÿ��Ԫ��֮�ͣ��������Ԫ��֮���Ƿ�Ϊ 1
 */

class Solution {
   public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> row(m), col(n);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                row[i] += mat[i][j];
                col[j] += mat[i][j];
            }
        int ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (mat[i][j] == 1 && row[i] == 1 && col[j] == 1) ans++;
        return ans;
    }
};