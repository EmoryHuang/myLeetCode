/*
 * @Descroption: LeetCode 47. 全排列 II
 * @Author: EmoryHuang
 * @Date: 2021-05-21 15:16:00
 * @解题思路:
 * 回溯法，遍历所有可能
 * 相比于[46.全排列]可包含重复数字，其实可以直接使用set免去去重麻烦
 *
 * 如果不使用set，那么就需要在深度优先时对重复数字进行判断
 */

class Solution {
   public:
    // 方法一：set
    // set<vector<int>> st;
    // vector<int> order;
    // void dfs(vector<int>& nums, vector<bool>& vis) {
    //     if (order.size() == nums.size()) {
    //         st.insert(order);
    //         return;
    //     }
    //     for (int i = 0; i < nums.size(); i++) {
    //         if (!vis[i]) {  // 如果未访问
    //             vis[i] = true;
    //             order.push_back(nums[i]);
    //             dfs(nums, vis);
    //             vis[i] = false;  // 撤销选择
    //             order.pop_back();
    //         }
    //     }
    // }
    // vector<vector<int>> permuteUnique(vector<int>& nums) {
    //     vector<bool> vis(nums.size(), false);
    //     dfs(nums, vis);
    //     vector<vector<int>> ans(st.begin(), st.end());
    //     return ans;
    // }

    // 方法二
    vector<vector<int>> ans;
    vector<int> order;
    void dfs(vector<int>& nums, vector<bool>& vis) {
        if (order.size() == nums.size()) {
            ans.push_back(order);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!vis[i]) {  // 如果未访问
                // 如果与前一个已访问的数字相同
                if (i > 0 && nums[i] == nums[i - 1] && vis[i - 1]) continue;
                vis[i] = true;
                order.push_back(nums[i]);
                dfs(nums, vis);
                vis[i] = false;  // 撤销选择
                order.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> vis(nums.size(), false);
        sort(nums.begin(), nums.end());
        dfs(nums, vis);
        return ans;
    }
};