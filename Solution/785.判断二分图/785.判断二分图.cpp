/*
 * @Descroption: LeetCode 785. 判断二分图
 * @Author: EmoryHuang
 * @Date: 2021-08-02 15:00:43
 * @Method:
 * 染色法判断二分图
 * 首先随意选取一个未染色的点进行染色，然后尝试将其相邻的点染成相反的颜色。
 * 如果邻接点已经被染色并且现有的染色与它应该被染的颜色不同，那么就说明不是二分图
 */

class Solution {
   public:
    vector<int> color;  // 0表示未染色，1表示白色，2表示黑色
    bool dfs(vector<vector<int>>& graph, int u, int c) {
        // u表示当前节点，c表示当前点的颜色
        color[u] = c;
        // 遍历u的邻接节点
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            // 如果相邻节点未染色
            if (color[v] == 0) {
                // 将相邻的点染成相反的颜色
                if (!dfs(graph, v, 3 - c)) return false;
            } else if (color[v] == c)
                //结点v已经着色，且和结点u颜色冲突
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        color.resize(n);
        bool flag = true;
        for (int i = 0; i < n; i++)
            // 如果当前节点未染色
            if (color[i] == 0)
                if (!dfs(graph, i, 1)) {
                    flag = false;
                    break;
                }
        return flag;
    }
};