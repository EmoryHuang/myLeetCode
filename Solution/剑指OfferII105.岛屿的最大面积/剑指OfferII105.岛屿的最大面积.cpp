/*
 * @Descroption: ��ָ Offer II 105. �����������
 * @Author: EmoryHuang
 * @Date: 2021-08-19 16:21:12
 * @Method:
 * ����һ�����鼯
 * ��ʼʱ��ÿ��λ�ö���Ϊ��������Χ��½�أ���ͺϲ�����¼ÿ����ͨͼ�Ľڵ�����
 * ��������BFS
 * ������ȱ�����ÿ����һ����ͽ����� 0����¼ÿ����ͨͼ�Ľڵ�������ȡ���ֵ
 * ��������DFS
 * �� BFS ���ƣ�ÿ����һ����ͽ����� 0����¼ÿ����ͨͼ�Ľڵ�������ȡ���ֵ
 */

class Solution {
   public:
    // ����һ�����鼯
    vector<int> parent, num;
    int find(int x) {
        if (x != parent[x]) parent[x] = find(parent[x]);
        return parent[x];
    }
    void _union(int x, int y) {
        int r1 = find(x), r2 = find(y);
        if (r1 != r2) {
            parent[r2] = r1;
            // ��������
            num[r1] += num[r2];
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<int> dx = {0, 1}, dy = {1, 0};
        int m = grid.size(), n = grid[0].size();
        // ��ʼ�����鼯
        for (int i = 0; i < m * n; i++) parent.push_back(i);
        num.resize(m * n);  // ���¼��ϴ�С
        int ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1) {
                    num[i * n + j] = 1;
                    // ֻ�����Һ����²鿴
                    for (int k = 0; k < 2; k++) {
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                            num[x * n + y] = 1;
                            _union(i * n + j, x * n + y);
                        }
                    }
                }
        return *max_element(num.begin(), num.end());
    }

    // ��������BFS
    // int m, n, ans = 0;
    // vector<int> dx = {0, -1, 0, 1}, dy = {1, 0, -1, 0};
    // void bfs(vector<vector<int>>& grid, int i, int j) {
    //     queue<pair<int, int>> q;
    //     q.push({i, j});
    //     grid[i][j] = 0;  // ���Ϊ����
    //     int cnt = 1;     // ��¼��ǰ����С
    //     while (!q.empty()) {
    //         auto [x, y] = q.front();
    //         q.pop();
    //         for (int i = 0; i < 4; i++) {
    //             int nx = x + dx[i];
    //             int ny = y + dy[i];
    //             if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
    //                 grid[nx][ny] = 0;  // ���Ϊ����
    //                 q.push({nx, ny});
    //                 cnt++;
    //             }
    //         }
    //     }
    //     ans = max(ans, cnt);
    // }
    // int maxAreaOfIsland(vector<vector<int>>& grid) {
    //     m = grid.size(), n = grid[0].size();
    //     for (int i = 0; i < m; i++)
    //         for (int j = 0; j < n; j++)
    //             if (grid[i][j] == 1) {
    //                 bfs(grid, i, j);
    //             }
    //     return ans;
    // }

    // ��������DFS
    // int m, n;
    // vector<int> dx = {0, -1, 0, 1}, dy = {1, 0, -1, 0};
    // int dfs(vector<vector<int>>& grid, int i, int j) {
    //     grid[i][j] = 0;  // ���Ϊ����
    //     int cnt = 1;
    //     for (int k = 0; k < 4; k++) {
    //         int nx = i + dx[k];
    //         int ny = j + dy[k];
    //         if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) cnt += dfs(grid, nx, ny);
    //     }
    //     return cnt;
    // }
    // int maxAreaOfIsland(vector<vector<int>>& grid) {
    //     m = grid.size(), n = grid[0].size();
    //     int ans = 0;
    //     for (int i = 0; i < m; i++)
    //         for (int j = 0; j < n; j++)
    //             if (grid[i][j] == 1) {
    //                 ans = max(ans, dfs(grid, i, j));
    //             }
    //     return ans;
    // }
};