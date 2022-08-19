/*
 * @Descroption: LeetCode 1387. 将整数按权重排序
 * @Author: EmoryHuang
 * @Date: 2021-08-27 15:23:58
 * @Method:
 * 直接 insert
 */

class Solution {
   public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) ans.insert(ans.begin() + index[i], nums[i]);
        return ans;
    }
};