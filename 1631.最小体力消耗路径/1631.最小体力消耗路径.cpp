/*
 * @Descroption: LeetCode 1631. 最小体力消耗路径
 * @Author: EmoryHuang
 * @Date: 2021-08-24 19:20:34
 * @Method:
 * 方法一：并查集
 * 将图中的所有边按照权值从小到大进行排序，并依次加入并查集中
 * 如果左上角和右下角从非连通状态变为连通状态，那么得到答案
 *
 * 方法二：二分 + BFS/DFS
 * 二分法判断体力消耗为 mid 时能否到达(n-1, n-1)
 * 具体来说，从(0, 0)开始进行广度优先遍历，
 * 若未超出边界并且高度小于等于 t，则标记为访问
 */

class Solution {
   public:
    // 方法一：并查集
    // vector<int> parent;
    // int find(int x) {
    //     if (x != parent[x]) parent[x] = find(parent[x]);
    //     return parent[x];
    // }
    // void merge(int x, int y) { parent[find(x)] = find(y); }
    // typedef tuple<int, int, int> tiii;
    // int minimumEffortPath(vector<vector<int>>& heights) {
    //     int m = heights.size(), n = heights[0].size();
    //     // 初始化并查集
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

    // 方法二：二分 + BFS/DFS
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
            // 二分法判断体力消耗为 mid 时能否到达(n-1, n-1)
            if (check(heights, mid))
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};