/*
 * @Descroption: LeetCode 1920. 基于排列构建数组
 * @Author: EmoryHuang
 * @Date: 2021-11-05 20:21:40
 * @Method:
 * 简单题
 */

class Solution {
   public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans;
        for (int num : nums) ans.push_back(nums[num]);
        return ans;
    }
};