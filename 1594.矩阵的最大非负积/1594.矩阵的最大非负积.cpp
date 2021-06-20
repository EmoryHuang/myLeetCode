/*
 * @Descroption: LeetCode 1594. ��������Ǹ���
 * @Author: EmoryHuang
 * @Date: 2021-06-20 13:46:00
 * @����˼·:
 * ��̬�滮
 * �� dp ʱ��Ҫ��������Ԫ�ص���������
 * ��ˣ�ͬʱά���������� maxpos �� minneg, �ֱ�洢�����ֵ����С��ֵ
 * ״̬ת�Ʒ���
 * �� grid[i][j] >= 0����
 * maxpos[i][j] = grid[i][j] * max(maxpos[i][j - 1], maxpos[i - 1][j])
 * minneg[i][j] = grid[i][j] * min(minneg[i][j - 1], minneg[i - 1][j])
 * �� grid[i][j] < 0����
 * maxpos[i][j] = grid[i][j] * min(minneg[i][j - 1], minneg[i - 1][j])
 * minneg[i][j] = grid[i][j] * max(maxpos[i][j - 1], maxpos[i - 1][j])
 */

class Solution {
   public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<long>> maxpos(m, vector<long>(n));  //�洢�����ֵ
        vector<vector<long>> minneg(m, vector<long>(n));   //�洢��С��ֵ
        // ��ʼ����һ�к͵�һ��
        maxpos[0][0] = minneg[0][0] = grid[0][0];
        for (int i = 1; i < m; i++) maxpos[i][0] = minneg[i][0] = maxpos[i - 1][0] * grid[i][0];
        for (int i = 1; i < n; i++) maxpos[0][i] = minneg[0][i] = maxpos[0][i - 1] * grid[0][i];
        // ״̬ת��
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++) {
                if (grid[i][j] >= 0) {
                    maxpos[i][j] = grid[i][j] * max(maxpos[i][j - 1], maxpos[i - 1][j]);
                    minneg[i][j] = grid[i][j] * min(minneg[i][j - 1], minneg[i - 1][j]);
                } else {
                    maxpos[i][j] = grid[i][j] * min(minneg[i][j - 1], minneg[i - 1][j]);
                    minneg[i][j] = grid[i][j] * max(maxpos[i][j - 1], maxpos[i - 1][j]);
                }
            }
        if (maxpos[m - 1][n - 1] < 0) return -1;
        return maxpos[m - 1][n - 1] % 1000000007;
    }
};