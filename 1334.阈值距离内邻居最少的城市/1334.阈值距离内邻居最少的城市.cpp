/*
 * @Descroption: LeetCode 1334. 阈值距离内邻居最少的城市
 * @Author: EmoryHuang
 * @Date: 2021-08-02 16:30:44
 * @Method:
 * 转换一下意思，也就是求一个源点，它在阈值内能够到达的城市数量最少
 * 遍历所有城市作为源点，使用spfa算法（Floyd, Djistra）求最短路径
 */

class Solution {
   public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // 构建邻接表
        unordered_map<int, vector<pair<int, int>>> mp;
        for (auto edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            mp[u].push_back({v, w});
            mp[v].push_back({u, w});
        }
        int ans = -1, mincnt = INT_MAX;
        // 遍历所有城市作为源点
        for (int i = 0; i < n; i++) {
            // spfa 算法计算最小距离
            vector<int> dis(n, INT_MAX);
            vector<bool> inq(n);
            queue<int> q;
            q.push(i);
            inq[i] = true;
            dis[i] = 0;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                inq[u] = false;
                for (int j = 0; j < mp[u].size(); j++) {
                    int v = mp[u][j].first;
                    int w = mp[u][j].second;
                    if (dis[v] > dis[u] + w) {
                        dis[v] = dis[u] + w;
                        if (!inq[v]) {
                            q.push(v);
                            inq[v] = true;
                        }
                    }
                }
            }
            int cnt = 0;
            for (int k = 0; k < n; k++)
                if (dis[k] <= distanceThreshold) cnt++;
            // 更新邻居最少的城市
            if (cnt <= mincnt) {
                mincnt = cnt;
                ans = i;
            }
        }
        return ans;
    }
};