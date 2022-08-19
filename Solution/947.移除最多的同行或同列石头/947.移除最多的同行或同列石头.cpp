/*
 * @Descroption: LeetCode 947. 移除最多的同行或同列石头
 * @Author: EmoryHuang
 * @Date: 2021-06-27 14:58:00
 * @解题思路:
 * 并查集
 * 遍历各个点，在同一行或者同一列则合并
 * 最后计算连通图个数，那么可以移除的石子的最大数量为 n - 连通图个数
 */

class Solution {
   public:
    int find(vector<int>& parent, int x) {
        if (parent[x] != x) parent[x] = find(parent, parent[x]);
        return parent[x];
    }
    void myunion(vector<int>& parent, int x, int y) { parent[find(parent, x)] = find(parent, y); }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> parent(n);
        for (int i = 0; i < n; i++) parent[i] = i;  // 初始化并查集
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                    // 在同一行或者同一列则合并
                    myunion(parent, i, j);
        int ans = 0;
        for (int i = 0; i < n; i++)
            if (parent[i] == i) ans++;  // 连通图个数
        return n - ans;
    }
};