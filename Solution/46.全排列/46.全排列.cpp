/*
 * @Descroption: LeetCode 46. 全排列
 * @Author: EmoryHuang
 * @Date: 2021-05-21 15:11:00
 * @解题思路:
 * 回溯法，遍历所有可能
 */

class Solution {
   public:
    vector<vector<int>> ans;
    vector<int> order;
    void dfs(vector<int>& nums, vector<bool>& vis) {
        if (order.size() == nums.size()) {
            ans.push_back(order);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!vis[i]) {  // 如果未访问
                vis[i] = true;
                order.push_back(nums[i]);
                dfs(nums, vis);
                vis[i] = false;  // 撤销选择
                order.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> vis(nums.size(), false);
        dfs(nums, vis);
        return ans;
    }
};