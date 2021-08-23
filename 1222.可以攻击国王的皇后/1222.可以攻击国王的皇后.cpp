/*
 * @Descroption: LeetCode 1222. 可以攻击国王的皇后
 * @Author: EmoryHuang
 * @Date: 2021-08-23 19:45:40
 * @Method:
 * 从国王出发，遍历8个方向，查看当前方向上是否有皇后
 */

class Solution {
   public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<int> dx = {0, -1, -1, -1, 0, 1, 1, 1}, dy = {1, 1, 0, -1, -1, -1, 0, 1};
        vector<vector<int>> grid(8, vector<int>(8));
        for (auto q : queens) grid[q[0]][q[1]] = 1;
        vector<vector<int>> ans;
        for (int i = 0; i < 8; i++) {
            int x = king[0] + dx[i], y = king[1] + dy[i];
            while (x >= 0 && x < 8 && y >= 0 && y < 8) {
                if (grid[x][y]) {
                    ans.push_back({x, y});
                    break;
                }
                x += dx[i];
                y += dy[i];
            }
        }
        return ans;
    }
};