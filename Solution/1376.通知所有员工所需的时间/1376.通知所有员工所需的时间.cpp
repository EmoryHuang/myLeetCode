/*
 * @Descroption: LeetCode 1376. 通知所有员工所需的时间
 * @Author: EmoryHuang
 * @Date: 2021-08-09 15:28:23
 * @Method:
 * 建有向图，dfs,bfs遍历
 * 方法一：DFS
 * 方法二：BFS
 */

class Solution {
   public:
    // 方法一：DFS
    // vector<vector<int>> mp;
    // int dfs(int cur, vector<int>& informTime) {
    //     int cnt = 0;
    //     for (auto child : mp[cur]) {
    //         cnt = max(cnt, dfs(child, informTime) + informTime[cur]);
    //     }
    //     return cnt;
    // }
    // int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
    //     if (n == 1) return 0;
    //     mp.resize(n);
    //     for (int i = 0; i < n; i++) {
    //         if (manager[i] != -1) mp[manager[i]].push_back(i);
    //     }
    //     return dfs(headID, informTime);
    // }

    // 方法二：BFS
    vector<vector<int>> mp;
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        if (n == 1) return 0;
        mp.resize(n);
        for (int i = 0; i < n; i++)
            if (manager[i] != -1) mp[manager[i]].push_back(i);
        queue<pair<int, int>> q;
        q.push({headID, 0});
        int ans = 0;
        while (!q.empty()) {
            auto [cur, val] = q.front();
            q.pop();
            ans = max(ans, val);
            for (auto child : mp[cur]) q.push({child, val + informTime[cur]});
        }
        return ans;
    }
};