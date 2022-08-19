/*
 * @Descroption: LeetCode 778. ˮλ������Ӿ������Ӿ
 * @Author: EmoryHuang
 * @Date: 2021-08-24 17:00:34
 * @Method:
 * ����һ�����鼯
 * ά��ÿ���߶ȶ�Ӧ��λ�ã�Ȼ���� t ʱ��ʱ�����λ�ã������ĸ��������
 * ��δ�����߽粢�Ҹ߶�С�ڵ��� t��tʱ�̸߶�Ϊt������ô���кϲ�
 * �����(0, 0) �� (n-1, n-1) �Ƿ���һ����ͨͼ�С�
 *
 * ������������ + BFS/DFS
 * ���ַ��ж� mid ʱ���ܷ񵽴�(n-1, n-1)
 * ������˵����(0, 0)��ʼ���й�����ȱ�����
 * ��δ�����߽粢�Ҹ߶�С�ڵ��� t������Ϊ����
 */

class Solution {
   public:
    // ����һ�����鼯
    vector<int> parent;
    int find(int x) {
        if (x != parent[x]) parent[x] = find(parent[x]);
        return parent[x];
    }
    void merge(int x, int y) { parent[find(x)] = find(y); }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 1) return 0;
        // ��ʼ�����鼯
        for (int i = 0; i < n * n; i++) parent.push_back(i);
        // �õ�ÿ���߶ȶ�Ӧ��λ��
        vector<pair<int, int>> pos(n * n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) pos[grid[i][j]] = {i, j};
        vector<int> dx = {0, -1, 0, 1}, dy = {1, 0, -1, 0};
        // ����ʱ�� t
        for (int t = 0; t < n * n; t++) {
            // t ʱ�̣��߶�Ϊ t ��λ�ã�
            auto [i, j] = pos[t];
            for (int k = 0; k < 4; k++) {
                int x = i + dx[k], y = j + dy[k];
                // ��δ�����߽粢�Ҹ߶�С�ڵ��� t
                if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] <= t) {
                    merge(i * n + j, x * n + y);
                }
            }
            if (find(0) == find(n * n - 1)) return t;
        }
        return -1;
    }

    // ������������ + BFS/DFS
    // bool check(vector<vector<int>>& grid, int t) {
    //     if (grid[0][0] > t) return false;
    //     vector<int> dx = {0, -1, 0, 1}, dy = {1, 0, -1, 0};
    //     int n = grid.size();
    //     vector<vector<int>> vis(n, vector<int>(n));
    //     vis[0][0] = 1;
    //     queue<pair<int, int>> q;
    //     q.push({0, 0});
    //     while (!q.empty()) {
    //         auto [i, j] = q.front();
    //         q.pop();
    //         for (int k = 0; k < 4; k++) {
    //             int x = i + dx[k], y = j + dy[k];
    //             if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] <= t && vis[x][y] == 0) {
    //                 q.push({x, y});
    //                 vis[x][y] = 1;
    //             }
    //         }
    //     }
    //     return vis[n - 1][n - 1] == 1;
    // }
    // int swimInWater(vector<vector<int>>& grid) {
    //     int n = grid.size();
    //     if (n == 1) return 0;
    //     int l = 0, r = n * n - 1;
    //     while (l < r) {
    //         int mid = l + (r - l) / 2;
    //         // ���ַ��ж� mid ʱ���ܷ񵽴�(n-1, n-1)
    //         if (check(grid, mid))
    //             r = mid;
    //         else
    //             l = mid + 1;
    //     }
    //     return l;
    // }
};