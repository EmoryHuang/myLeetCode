/*
 * @Descroption: LeetCode 802. 找到最终的安全状态
 * @Author: EmoryHuang
 * @Date: 2021-08-05 14:17:50
 * @Method:
 * 反向图 + 拓扑排序
 * 统计每个节点的出度，并将图存储为反向图
 * 首先将出度为 0 的节点入队
 * 通过拓扑排序，不断去除边，然后将出度为 0 的节点入队
 * 最后统计出度为 0 的节点
 */

class Solution {
   public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        unordered_map<int, vector<int>> mp;
        vector<int> outdegree(n);
        queue<int> q;
        for (int i = 0; i < n; i++) {
            // 统计所有节点的出度
            outdegree[i] = graph[i].size();
            if (!outdegree[i])
                // 将出度为 0 的节点入队
                q.push(i);
            else
                // 构建反向图
                for (int node : graph[i]) mp[node].push_back(i);
        }
        // 拓扑排序
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int ne : mp[node]) {
                if (--outdegree[ne] == 0) q.push(ne);
            }
        }
        vector<int> ans;
        // 统计出度为 0 的节点
        for (int i = 0; i < n; i++)
            if (!outdegree[i]) ans.push_back(i);
        return ans;
    }
};