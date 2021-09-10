/*
 * @Descroption: LeetCode 1514. 概率最大的路径
 * @Author: EmoryHuang
 * @Date: 2021-06-16 13:47:00
 * @解题思路:
 * spfa算法
 * 用邻接矩阵存储图
 * 求得概率最大的路径
 */

class Solution {
   public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start,
                          int end) {
        vector<vector<pair<int, double>>> mp(n);
        vector<double> d(n, 0);
        vector<int> inq(n, 0);
        for (int i = 0; i < edges.size(); i++) {
            mp[edges[i][0]].emplace_back(edges[i][1], succProb[i]);
            mp[edges[i][1]].emplace_back(edges[i][0], succProb[i]);
        }
        queue<int> q;
        q.push(start);
        inq[start] = 1;  // 起点在队列中
        d[start] = 1;    // 起点到自身的概率为1
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            inq[u] = 0;  // u不在队列中
            // 遍历邻接节点
            for (int j = 0; j < mp[u].size(); j++) {
                int v = mp[u][j].first;
                double dis = mp[u][j].second;
                if (d[v] < d[u] * dis) {  // 概率更大的路径
                    d[v] = d[u] * dis;
                    if (!inq[v]) {  // 如果v不在队列中
                        q.push(v);
                        inq[v] = 1;
                    }
                }
            }
        }
        return d[end];
    }
};