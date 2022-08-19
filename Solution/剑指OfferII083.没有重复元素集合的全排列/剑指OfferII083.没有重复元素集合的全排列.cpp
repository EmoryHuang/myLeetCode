/*
 * @Descroption: 剑指 Offer II 083. 没有重复元素集合的全排列
 * @Author: EmoryHuang
 * @Date: 2021-08-06 16:50:05
 * @Method:
 * 简单回溯
 * 由于没有重复元素，因此可以直接判断元素是否在排列中
 * 当然也可以使用额外空间记录元素是否使用
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
                vis[i] = true;
                path.push_back(nums[i]);
                dfs(nums);
                vis[i] = false;
                path.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vis.resize(nums.size());
        dfs(nums);
        return ans;
    }
};