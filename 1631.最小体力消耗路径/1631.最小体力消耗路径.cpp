/*
 * @Descroption: LeetCode 1631. ��С��������·��
 * @Author: EmoryHuang
 * @Date: 2021-08-24 19:20:34
 * @Method:
 * ����һ�����鼯
 * ��ͼ�е����б߰���Ȩֵ��С����������򣬲����μ��벢�鼯��
 * ������ϽǺ����½Ǵӷ���ͨ״̬��Ϊ��ͨ״̬����ô�õ���
 *
 * ������������ + BFS/DFS
 * ���ַ��ж���������Ϊ mid ʱ�ܷ񵽴�(n-1, n-1)
 * ������˵����(0, 0)��ʼ���й�����ȱ�����
 * ��δ�����߽粢�Ҹ߶�С�ڵ��� t������Ϊ����
 */

class Solution {
   public:
    // ����һ�����鼯
    // vector<int> parent;
    // int find(int x) {
    //     if (x != parent[x]) parent[x] = find(parent[x]);
    //     return parent[x];
    // }
    // void merge(int x, int y) { parent[find(x)] = find(y); }
    // typedef tuple<int, int, int> tiii;
    // int minimumEffortPath(vector<vector<int>>& heights) {
    //     int m = heights.size(), n = heights[0].size();
    //     // ��ʼ�����鼯
    //     for (int i = 0; i < 1000001; i++) parent.push_back(i);
    //     vector<tiii> edges;
    //     for (int i = 0; i < m; i++)
    //         for (int j = 0; j < n; j++) {
    //             int pos = i * n + j;
    //             if (i > 0) edges.push_back({abs(heights[i][j] - heights[i - 1][j]), pos, pos - n});
    //             if (j > 0) edges.push_back({abs(heights[i][j] - heights[i][j - 1]), pos, pos - 1});
    //         }
    //     sort(edges.begin(), edges.end(), [](tiii a, tiii b) { return get<0>(a) < get<0>(b); });
    //     for (auto e : edges) {
    //         int d = get<0>(e), u = get<1>(e), v = get<2>(e);
    //         merge(u, v);
    //         if (find(0) == find(m * n - 1)) return d;
    //     }
    //     return 0;
    // }

    // ������������ + BFS/DFS
    bool check(vector<vector<int>>& heights, int t) {
        vector<int> dx = {0, -1, 0, 1}, dy = {1, 0, -1, 0};
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> vis(m, vector<int>(n));
        vis[0][0] = 1;
        queue<pair<int, int>> q;
        q.push({0, 0});
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                int x = i + dx[k], y = j + dy[k];
                if (x >= 0 && x < m && y >= 0 && y < n && abs(heights[x][y] - heights[i][j]) <= t && vis[x][y] == 0) {
                    q.push({x, y});
                    vis[x][y] = 1;
                }
            }
        }
        return vis[m - 1][n - 1] == 1;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int l = 0, r = 1000000 - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            // ���ַ��ж���������Ϊ mid ʱ�ܷ񵽴�(n-1, n-1)
            if (check(heights, mid))
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};