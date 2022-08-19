/*
 * @Descroption: LeetCode 684. 冗余连接
 * @Author: EmoryHuang
 * @Date: 2021-08-01 14:31:49
 * @Method:
 * 并查集
 * 如果两个顶点不位于同一个连通分量中，那么合并这两个顶点不会导致环的出现
 * 如果位于同一个连通分量中，那么合并这两个顶点会导致环的出现
 */

class Solution {
   public:
    vector<int> parent;
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void _union(int x, int y) { parent[find(x)] = find(y); }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        for (int i = 0; i < n + 1; i++) parent.push_back(i);
        for (auto edge : edges) {
            // 如果不位于同一个连通分量中
            // 那么合并这两个顶点不会导致环的出现
            if (find(edge[0]) != find(edge[1])) 
                _union(edge[0], edge[1]);
            // 如果位于同一个连通分量中
            // 那么合并这两个顶点会导致环的出现
            else
                return {edge[0], edge[1]};
        }
        return {};
    }
};