/*
 * @Descroption: LeetCode 547. 省份数量
 * @Author: EmoryHuang
 * @Date: 2021-08-01 13:56:25
 * @Method:
 * 经典问题，求连通分量数
 * 方法一：并查集
 * 如果两个城市属于相同的连通分量，则合并
 * 方法二：dfs
 * 遍历所有城市，对于每个城市，如果该城市尚未被访问过，则从该城市开始深度优先搜索
 * 遍历完全部城市以后，即可得到连通分量的总数
 */

class Solution {
   public:
    // 方法一：并查集
    vector<int> parent;
    int find(int x) {
        if (x != parent[x]) parent[x] = find(parent[x]);
        return parent[x];
    }
    void _union(int x, int y) { parent[find(x)] = find(y); }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        for (int i = 0; i < n; i++) parent.push_back(i);
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (isConnected[i][j] == 1) _union(i, j);
        int ans = 0;
        for (int i = 0; i < n; i++)
            if (parent[i] == i) ans++;
        return ans;
    }

    // 方法二：dfs
    // vector<int> vis;
    // void dfs(vector<vector<int>>& isConnected, int i) {
    //     for (int j = 0; j < isConnected.size(); j++) {
    //         if (isConnected[i][j] == 1 && vis[j] == 0) {
    //             vis[j] = 1;
    //             dfs(isConnected, j);
    //         }
    //     }
    // }
    // int findCircleNum(vector<vector<int>>& isConnected) {
    //     int n = isConnected.size();
    //     int ans = 0;
    //     vis.resize(n);
    //     for (int i = 0; i < n; i++)
    //         if (vis[i] == 0) {
    //             dfs(isConnected, i);
    //             ans++;
    //         }
    //     return ans;
    // }
};