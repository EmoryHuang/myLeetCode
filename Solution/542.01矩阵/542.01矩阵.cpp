/*
 * @Descroption: LeetCode 542. 01 矩阵
 * @Author: EmoryHuang
 * @Date: 2021-07-30 15:09:25
 * @Method:
 * 从 0 的位置开始进行广度优先搜索
 * 每次搜索到一个 1，就可以得到 0 到这个 1 的最短距离
 * 为了简便，将非零元素标识为 -1 代表未访问
 */

class Solution {
   public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        queue<vector<int>> q;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (mat[i][j] == 0)
                    q.push({i, j});
                else
                    mat[i][j] = -1;
        vector<int> dx = {0, -1, 0, 1};
        vector<int> dy = {1, 0, -1, 0};
        while (!q.empty()) {
            auto point = q.front();
            int x = point[0], y = point[1];
            q.pop();
            for (int i = 0; i < 4; i++) {
                int _x = x + dx[i];
                int _y = y + dy[i];
                if (_x >= 0 && _x < n && _y >=0 && _y < m && mat[_x][_y] == -1){
                    mat[_x][_y] = mat[x][y] + 1;
                    q.push({_x, _y});
                }
            }
        }
        return mat;
    }
};