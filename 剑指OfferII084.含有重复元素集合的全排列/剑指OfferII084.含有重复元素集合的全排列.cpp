/*
 * @Descroption: 剑指 Offer II 084. 含有重复元素集合的全排列
 * @Author: EmoryHuang
 * @Date: 2021-08-06 17:08:44
 * @Method:
 * 简单回溯
 * 由于有重复元素，因此可以在没有重复元素的基础上，判断当前元素是否为重复元素即可
 */

class Solution {
   public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> vis;
    void dfs(vector<int> nums) {
        if (path.size() == nums.size()) {
            ans.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!vis[i]) {
                if (i > 0 && nums[i] == nums[i - 1] && vis[i - 1]) continue;
                vis[i] = true;
                path.push_back(nums[i]);
                dfs(nums);
                vis[i] = false;
                path.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vis.resize(nums.size());
        sort(nums.begin(), nums.end());
        dfs(nums);
        return ans;
    }
};