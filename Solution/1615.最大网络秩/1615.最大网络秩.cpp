/*
 * @Descroption: LeetCode 1615. 最大网络秩
 * @Author: EmoryHuang
 * @Date: 2021-08-10 20:39:30
 * @Method:
 * 建图，统计每个节点的度
 * 遍历节点对，寻找度之和最大的节点对
 * 若这两个节点对之间有路径，则减1
 */

class Solution {
   public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int, set<int>> graph;
        vector<int> degree(n);
        for (int i = 0; i < roads.size(); i++) {
            graph[roads[i][0]].insert(roads[i][1]);
            graph[roads[i][1]].insert(roads[i][0]);
            // 统计节点的出入度
            degree[roads[i][0]]++;
            degree[roads[i][1]]++;
        }
        int ans = 0, sum = 0;
        for (int i = 1; i < n; i++)
            for (int j = 0; j < i; j++) {
                sum = degree[i] + degree[j];
                // 如果节点对之间有路径
                if (graph[i].count(j)) sum -= 1;
                ans = max(ans, sum);
            }
        return ans;
    }
};