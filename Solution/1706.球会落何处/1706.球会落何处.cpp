/*
 * @Descroption: LeetCode 1706. �����δ�
 * @Author: EmoryHuang
 * @Date: 2022-02-24 09:12:38
 * @Method:
 * ģ��
 * ���ڵ�ǰС��λ��[x, y]��ÿ�ο����ƶ���[x+1, y+1]����[x+1, y-1]
 * ��ô������ next = y + grid[x][y] ��ʾС����һ��λ�õ�y����
 * �������߽���˵������ס��
 * �� grid[x][y] != grid[x][next] ��˵������ס
 */

class Solution {
   public:
    int m, n;
    int next_pos(vector<vector<int>>& grid, int i) {
        int x = 0, y = i;
        while (x < m) {
            int next = y + grid[x][y];
            // ����ס
            if (next < 0 || next >= n) return -1;
            if (grid[x][y] != grid[x][next]) return -1;
            x++;
            y = next;
        }
        return y;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            ans.push_back(next_pos(grid, i));
        }
        return ans;
    }
};