/*
 * @Descroption: LeetCode 1267. ͳ�Ʋ���ͨ�ŵķ�����
 * @Author: EmoryHuang
 * @Date: 2021-07-15 20:26:20
 * @����˼·:
 * ��������
 * ��һ��ͳ��ÿ��ÿ�з�����������
 * �ڶ������ÿ��ÿ�з������������ж��Ƿ�Ϊ��ͨ
 */

class Solution {
   public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> row(n), col(m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 1) {
                    row[i]++;
                    col[j]++;
                }
        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 1 && (row[i] > 1 || col[j] > 1)) ans++;
        return ans;
    }
};