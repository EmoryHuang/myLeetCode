/*
 * @Descroption: LeetCode 1030. 距离顺序排列矩阵单元格
 * @Author: EmoryHuang
 * @Date: 2021-08-18 19:47:55
 * @Method:
 * 方法一：直接排序
 * 将所有位置加入数组，然后按曼哈顿距离排序
 * 方法二：BFS
 * 按照广度优先遍历的思想，向上下左右延申，入队的顺序实际上就是曼哈顿距离
 */

class Solution {
   public:
    // 方法一：直接排序
    // vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
    //     vector<vector<int>> ans;
    //     for (int i = 0; i < rows; i++)
    //         for (int j = 0; j < cols; j++) ans.push_back({i, j});
    //     sort(ans.begin(), ans.end(), [rCenter, cCenter](vector<int> a, vector<int> b) {
    //         return abs(a[0] - rCenter) + abs(a[1] - cCenter) < abs(b[0] - rCenter) + abs(b[1] - cCenter);
    //     });
    //     return ans;
    // }

    // 方法二：BFS
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<int> dx = {0, -1, 0, 1}, dy = {1, 0, -1, 0};
        queue<pair<int, int>> q;
        q.push({rCenter, cCenter});
        vector<vector<bool>> vis(rows, vector<bool>(cols));
        vis[rCenter][cCenter] = true;
        vector<vector<int>> ans;
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            ans.push_back({r, c});
            for (int i = 0; i < 4; i++) {
                int nr = r + dx[i];
                int nc = c + dy[i];
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && !vis[nr][nc]) {
                    vis[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
        return ans;
    }
};