/*
 * @Descroption: LeetCode 1252. ����ֵ��Ԫ�����Ŀ
 * @Author: EmoryHuang
 * @Date: 2021-07-15 20:09:02
 * @����˼·:
 * ģ�ⷨ��ģ���ÿ��ÿ�еļӷ���Ȼ�����ͳ�������ĸ���
 */

class Solution {
   public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<vector<int>> mat(m, vector<int>(n));
        for (auto ind : indices) {
            int row = ind[0], col = ind[1];
            for (int i = 0; i < n; i++) mat[row][i]++;
            for (int i = 0; i < m; i++) mat[i][col]++;
        }
        int ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (mat[i][j] % 2 == 1) ans++;
        return ans;
    }
};