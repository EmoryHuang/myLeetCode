/*
 * @Descroption: LeetCode 1706. 球会落何处
 * @Author: EmoryHuang
 * @Date: 2022-02-24 09:12:38
 * @Method:
 * 模拟
 * 对于当前小球位置[x, y]，每次可以移动到[x+1, y+1]或者[x+1, y-1]
 * 那么可以用 next = y + grid[x][y] 表示小球下一个位置的y坐标
 * 若超出边界则说明被卡住；
 * 若 grid[x][y] != grid[x][next] 则说明被卡住
 */

class Solution {
   public:
    int m, n;
    int next_pos(vector<vector<int>>& grid, int i) {
        int x = 0, y = i;
        while (x < m) {
            int next = y + grid[x][y];
            // 被卡住
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