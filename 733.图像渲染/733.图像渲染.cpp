/*
 * @Descroption: LeetCode 733. 图像渲染
 * @Author: EmoryHuang
 * @Date: 2021-08-11 20:48:25
 * @Method:
 * dfs
 * 从给定的起点开始，进行深度优先搜索
 * 每次搜索到一个方格时，如果其与初始位置的方格颜色相同，就将该方格的颜色更新
 */

class Solution {
   public:
    vector<int> dx = {0, -1, 0, 1}, dy = {1, 0, -1, 0};
    int old, m, n;
    void dfs(vector<vector<int>>& image, int x, int y, int newColor) {
        if (x >= 0 && x < m && y >= 0 && y < n && image[x][y] == old) {
            image[x][y] = newColor;
            for (int i = 0; i < 4; i++) {
                dfs(image, x + dx[i], y + dy[i], newColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor) return image;
        m = image.size(), n = image[0].size();
        old = image[sr][sc];
        dfs(image, sr, sc, newColor);
        return image;
    }
};