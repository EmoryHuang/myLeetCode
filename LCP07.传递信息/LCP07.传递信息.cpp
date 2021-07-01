/*
 * @Descroption: LCP 07. 传递信息
 * @Author: EmoryHuang
 * @Date: 2021-07-01 13:47:00
 * @解题思路:
 * 总体的思路还是简单的，建立邻接矩阵
 * 判断当前节点是否到达目标节点，并且步数为 k
 * 方法一：DFS
 * 方法二：BFS
 */

class Solution {
   public:
    // 方法一：DFS
    int numWays(int n, vector<vector<int>>& relation, int k) {
        vector<vector<int>> map(n);
        int ans = 0;
        for (auto p : relation) map[p[0]].push_back(p[1]);
        function<void(int, int)> dfs = [&](int cur, int step) {
            if (step == k) {
                if (cur == n - 1) ans++;
                return;
            }
            for (auto next : map[cur]) dfs(next, step + 1);
        };
        dfs(0, 0);
        return ans;
    }

    // 方法二：BFS
    // int numWays(int n, vector<vector<int>>& relation, int k) {
    //     vector<vector<int>> map(n);
    //     int ans = 0;
    //     for (auto p : relation) map[p[0]].push_back(p[1]);
    //     queue<pair<int, int>> q;
    //     q.push({0, 0});  // 记录当前节点以及到达步数
    //     while (!q.empty()) {
    //         auto [cur, step] = q.front();
    //         q.pop();
    //         if (step > k) break;
    //         // 找到一条路径
    //         if (cur == n - 1 && step == k) ans++;
    //         for (auto next : map[cur]) q.push({next, step + 1});
    //     }
    //     return ans;
    // }
};