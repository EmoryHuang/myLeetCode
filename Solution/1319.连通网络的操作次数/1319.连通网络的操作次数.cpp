/*
 * @Descroption: LeetCode 1319. 连通网络的操作次数
 * @Author: EmoryHuang
 * @Date: 2021-08-01 14:08:48
 * @Method:
 * 并查集求连通分量数
 * 每成功进行一次合并操作，连通分量数就会减少 1
 */

class Solution {
   public:
    vector<int> parent;
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void _union(int x, int y) { parent[find(x)] = find(y); }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int edges = connections.size();
        if (edges < n - 1) return -1;
        for (int i = 0; i < n; i++) parent.push_back(i);
        for (auto con : connections) _union(con[0], con[1]);
        int ans = 0;
        for (int i = 0; i < n; i++)
            if (parent[i] == i) ans++;
        return ans - 1;
    }
};