/*
 * @Descroption: LeetCode 207. 课程表
 * @Author: EmoryHuang
 * @Date: 2021-05-13 19:40:36
 * @解题思路: 拓扑排序
 * 使用邻接表存储图，初始时，所有入度为 0 的节点都被放入队列中，它们就是可以作为拓扑排序最前面的节点
 * 在广度优先搜索的每一步中，取出队首的节点 u，并遍历 u 的邻接结点，若入度为 0，则入队
 */

class Solution {
   public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> inDegree(numCourses);
        for (auto p : prerequisites) {
            adj[p[1]].push_back(p[0]);
            inDegree[p[0]]++;
        }
        queue<int> q;
        int num = 0;  // 记录加入拓扑序列的顶点数
        for (int i = 0; i < numCourses; i++)
            if (inDegree[i] == 0) q.push(i);  // 将入度为0的顶点入队
        while (!q.empty()) {
            num++;
            int u = q.front();  // 取出队首元素
            q.pop();
            for (auto v : adj[u]) {
                inDegree[v]--;                    // v的入度减1
                if (inDegree[v] == 0) q.push(v);  // 入度为0则入队
            }
        }
        return num == numCourses;
    }
};