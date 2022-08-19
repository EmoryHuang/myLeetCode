/*
 * @Descroption: LeetCode 1975. ������
 * @Author: EmoryHuang
 * @Date: 2021-09-23 19:26:47
 * @Method:
 * ���������������ż������ô���и������ܱ������
 * �����������������������ôֻ��Ҫ��¼����ֵ��С����
 */

class Solution {
   public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long ans = 0;
        // ��¼����������������ֵ��С����
        int cnt = 0, m = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans += abs(matrix[i][j]);
                if (matrix[i][j] <= 0) cnt++;
                m = min(m, abs(matrix[i][j]));
            }
        }
        if (cnt % 2 == 0) return ans;
        return ans - 2 * m;
    }
};