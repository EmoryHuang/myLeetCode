/*
 * @Descroption: LeetCode 210. 课程表 II
 * @Author: EmoryHuang
 * @Date: 2021-10-23 14:46:05
 * @Method:
 * 拓扑排序
 * 维护一个队列，将入度为 0 的节点入队，然后将其连接的节点入度减一
 * 直到队列为空
 */

class Solution {
   public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> edges;
        vector<int> indegree(numCourses);
        vector<int> ans;
        // 建立邻接表
        for (auto p : prerequisites) {
            edges[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        queue<int> q;
        // 将入度为 0 的节点入队
        for (int i = 0; i < numCourses; i++)
            if (indegree[i] == 0) q.push(i);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            ans.push_back(u);
            for (int v : edges[u])
                if (--indegree[v] == 0) q.push(v);
        }
        if (ans.size() != numCourses)
            return {};
        return ans;
    }
};