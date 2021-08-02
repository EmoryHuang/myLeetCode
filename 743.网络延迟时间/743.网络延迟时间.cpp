/*
 * @Descroption: LeetCode 743. 网络延迟时间
 * @Author: EmoryHuang
 * @Date: 2021-08-02 14:10:16
 * @Method:
 * 从 k 点出发，到其他点 x 的最短距离的最大值
 * 方法一：SPFA算法
 * 方法二：Floyd算法
 * 方法三：朴素dijkstra算法
 */

class Solution {
   public:
    // 方法一：SPFA算法
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // 建立邻接表
        unordered_map<int, vector<pair<int, int>>> mp;
        for (auto time : times) {
            int u = time[0], v = time[1], w = time[2];
            mp[u].push_back({v, w});
        }
        vector<int> d(n + 1, INT_MAX);  // 第一个节点不考虑
        queue<int> q;
        vector<bool> inq(n + 1, false);
        d[k] = d[0] = 0;
        q.push(k);
        inq[k] = true;  // 节点是否在队列中
        while (!q.empty()) {
            int u = q.front();  // 取队首元素
            inq[u] = false;
            q.pop();
            // 遍历与u相邻的节点
            for (int j = 0; j < mp[u].size(); j++) {
                int v = mp[u][j].first;   // 节点编号
                int w = mp[u][j].second;  // 边权
                if (d[v] > d[u] + w) {    // 更新最短距离
                    d[v] = d[u] + w;
                    if (!inq[v]) {
                        q.push(v);
                        inq[v] = true;
                    }
                }
            }
        }
        for (int dis : d)
            if (dis == INT_MAX) return -1;
        return *max_element(d.begin(), d.end());
    }

    // 方法二：Floyd算法
    // int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    //     int INF = 0x3f3f3f3f;
    //     vector<vector<int>> mp(n + 1, vector<int>(n + 1, INF));
    //     vector<bool> vis(n + 1, false);
    //     // 建立邻接矩阵
    //     for (int i = 1; i <= n; i++) mp[i][i] = mp[i][0] = mp[0][i] = 0;
    //     for (auto time : times) {
    //         int u = time[0], v = time[1], w = time[2];
    //         mp[u][v] = w;
    //     }
    //     for (int t = 1; t <= n; t++)
    //         for (int i = 1; i <= n; i++)
    //             for (int j = 1; j <= n; j++) mp[i][j] = min(mp[i][j], mp[i][t] + mp[t][j]);
    //     for (int i = 1; i <= n; i++)
    //         if (mp[k][i] == INF) return -1;
    //     return *max_element(mp[k].begin(), mp[k].end());
    // }

    // 方法三：朴素dijkstra算法
    // int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    //     int INF = 0x3f3f3f3f;
    //     vector<vector<int>> mp(n + 1, vector<int>(n + 1, INF));
    //     vector<int> d(n + 1, INF);
    //     vector<bool> vis(n + 1, false);
    //     // 建立邻接矩阵
    //     for (int i = 1; i <= n; i++) mp[i][i] = 0;
    //     for (auto time : times) {
    //         int u = time[0], v = time[1], w = time[2];
    //         mp[u][v] = w;
    //     }
    //     d[k] = d[0] = 0;  // 起点到自身的距离为0
    //     for (int i = 1; i <= n; i++) {
    //         int u = -1;  // 寻找距离最小的点
    //         for (int j = 1; j <= n; j++) {
    //             if (!vis[j] && (u == -1 || d[u] > d[j])) u = j;
    //         }
    //         vis[u] = true;
    //         // 以u为中介点
    //         for (int v = 1; v <= n; v++) d[v] = min(d[v], d[u] + mp[u][v]);
    //     }
    //     for (int dis : d)
    //         if (dis == INF) return -1;
    //     return *max_element(d.begin(), d.end());
    // }
};