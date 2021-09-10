/*
 * @Descroption: LeetCode 1583. 统计不开心的朋友
 * @Author: EmoryHuang
 * @Date: 2021-08-14 13:55:38
 * @Method:
 * 模拟
 * 获得 y 在 x 处亲近程度的下标并记录配对情况
 * 遍历每个人 x, 获得 x 的配对 y 以及 y 与 x 的亲密程度次序 index
 * 遍历每个可能的 u，0 ~ index - 1，找到与朋友 u 配对的朋友 v
 * 如果 u 与 x 的亲近程度胜过 u 与 v，则 x 不开心
 */

class Solution {
   public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        vector<vector<int>> order(n, vector<int>(n));
        vector<int> pair(n);
        // 获得 y 在 x 处亲近程度的下标
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n - 1; j++) order[i][preferences[i][j]] = j;
        // 记录配对情况
        for (auto p : pairs) {
            pair[p[0]] = p[1];
            pair[p[1]] = p[0];
        }
        int ans = 0;
        for (int x = 0; x < n; x++) {
            // 获得 x 的配对 y 以及 y 与 x 的亲密程度次序
            int y = pair[x];
            int index = order[x][y];
            for (int i = 0; i < index; i++) {
                // 遍历每个可能的 u，找到与朋友 u 配对的朋友 v
                int u = preferences[x][i];
                int v = pair[u];
                // 如果 u 与 x 的亲近程度胜过 u 与 v
                if (order[u][x] < order[u][v]) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};