/*
 * @Descroption: LCP 07. ������Ϣ
 * @Author: EmoryHuang
 * @Date: 2021-07-01 13:47:00
 * @����˼·:
 * �����˼·���Ǽ򵥵ģ������ڽӾ���
 * �жϵ�ǰ�ڵ��Ƿ񵽴�Ŀ��ڵ㣬���Ҳ���Ϊ k
 * ����һ��DFS
 * ��������BFS
 */

class Solution {
   public:
    // ����һ��DFS
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

    // ��������BFS
    // int numWays(int n, vector<vector<int>>& relation, int k) {
    //     vector<vector<int>> map(n);
    //     int ans = 0;
    //     for (auto p : relation) map[p[0]].push_back(p[1]);
    //     queue<pair<int, int>> q;
    //     q.push({0, 0});  // ��¼��ǰ�ڵ��Լ����ﲽ��
    //     while (!q.empty()) {
    //         auto [cur, step] = q.front();
    //         q.pop();
    //         if (step > k) break;
    //         // �ҵ�һ��·��
    //         if (cur == n - 1 && step == k) ans++;
    //         for (auto next : map[cur]) q.push({next, step + 1});
    //     }
    //     return ans;
    // }
};