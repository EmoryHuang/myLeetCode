/*
 * @Descroption: LeetCode 1351. ͳ����������еĸ���
 * @Author: EmoryHuang
 * @Date: 2021-06-22 19:32:00
 * @����˼·:
 * ����ǰ��Ϊ��������ôʣ�µ�����ȻҲ�Ǹ����������������һ��
 */

class Solution {
   public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] < 0) {
                    cnt += n - j;
                    break;
                }
        return cnt;
    }
};