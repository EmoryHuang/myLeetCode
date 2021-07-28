/*
 * @Descroption: LeetCode 851. 喧闹和富有
 * @Author: EmoryHuang
 * @Date: 2021-07-28 14:23:33
 * @Method:
 * dfs
 * 存储 richer 中的富裕关系
 * 遍历每一个人，找到比它富裕的人，dfs寻找比这个人更富裕的人
 * 在dfs的过程中，更新最小的安静值
 */

class Solution {
   public:
    vector<vector<int>> mp;
    vector<int> ans;
    int dfs(vector<int> quiet, int x) {
        if (ans[x] == -1) {
            ans[x] = x;
            // 对于每一个比x更富裕的人
            for (auto rich : mp[x]) {
                // dfs找到比这个人更富裕的人
                int more_rich = dfs(quiet, rich);
                // 更新最小的安静值
                if (quiet[more_rich] < quiet[ans[x]]) ans[x] = more_rich;
            }
        }
        return ans[x];
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        mp.resize(n);
        ans.resize(n, -1);
        // 存储富裕关系
        for (auto rich : richer) mp[rich[1]].push_back(rich[0]);
        for (int i = 0; i < n; i++) dfs(quiet, i);
        return ans;
    }
};