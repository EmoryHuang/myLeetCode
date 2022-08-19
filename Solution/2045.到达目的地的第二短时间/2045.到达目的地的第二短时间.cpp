/*
 * @Descroption: LeetCode 2045. 到达目的地的第二短时间
 * @Author: EmoryHuang
 * @Date: 2022-01-24 18:31:48
 * @Method:
 * BFS
 * 同时维护最短路和次短路，若 d < min_d[x]，则先用 min_d[x] 更新 sec_d[x]，再用 d 更新 min_d[x]
 * 若 min_d[x] < d < sec_d[x]，则用 d 更新 sec_d[x]
 * 对于红绿灯的切换问题: 经过 step 步
 * 若 step % change 为奇，则为红灯，等待时间为 change - (step % change)
 * 若 step % change 为偶，则为绿灯，等待时间为 0
 * */

class Solution {
   public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> map(n + 1);
        for (auto& edge : edges) {
            map[edge[0]].push_back(edge[1]);
            map[edge[1]].push_back(edge[0]);
        }
        // min_d 和 sec_d 分别表示从 1 到 i 的最小和第二小的路径长度
        vector<int> min_d(n + 1, 0x3f3f3f3f), sec_d(n + 1, 0x3f3f3f3f);
        min_d[1] = 0;
        queue<pair<int, int>> q;
        q.push({1, 0});
        while (!q.empty()) {
            auto [u, dis] = q.front();
            q.pop();
            for (auto v : map[u]) {
                int d = dis + 1;
                if (d < min_d[v]) {
                    sec_d[v] = min_d[v];
                    min_d[v] = d;
                    q.push({v, min_d[v]});
                    q.push({v, sec_d[v]});
                } else if (d < sec_d[v] && d > min_d[v]) {
                    sec_d[v] = d;
                    q.push({v, sec_d[v]});
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < sec_d[n]; i++) {
            int a = ans / change, b = ans % change;
            int wait = a % 2 == 0 ? 0 : change - b;
            ans += wait + time;
        }
        return ans;
    }
};