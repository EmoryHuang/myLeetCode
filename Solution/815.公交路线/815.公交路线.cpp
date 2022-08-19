/*
 * @Descroption: LeetCode 815. 公交路线
 * @Author: EmoryHuang
 * @Date: 2021-06-28 13:42:00
 * @解题思路:
 * BFS，先找线路，然后再根据线路找车站
 * 使用 map 记录 (站点编号，[站点所在的路线编号])
 * 采样广度优先的方法，遍历当前站点所在的路线，若当前路线未访问，则遍历这条路线的所有站点
 * 若找到了 target，那么就返回已经遍历的路线的数目
 */

class Solution {
   public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;
        int n = routes.size();
        queue<int> q;
        unordered_map<int, vector<int>> map;  // (站点编号，[站点所在的路线编号])
        vector<int> vis(n);                   // 记录路线是否访问
        int ans = 1;
        for (int i = 0; i < n; i++)
            for (auto station : routes[i]) map[station].push_back(i);
        q.push(source);
        while (!q.empty()) {
            int len = q.size();
            for (int i = 0; i < len; i++) {
                int cur = q.front();  // 当前站点
                q.pop();
                for (auto route : map[cur]) {  // 遍历当前站点所在的路线
                    if (!vis[route]) {         // 若当前路线未访问
                        vis[route] = 1;
                        // 遍历这条路线的所有站点
                        for (auto station : routes[route]) {
                            // 到达 target
                            if (station == target) return ans;
                            q.push(station);
                        }
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};