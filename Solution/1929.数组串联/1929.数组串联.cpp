/*
 * @Descroption: LeetCode 1929. 数组串联
 * @Author: EmoryHuang
 * @Date: 2021-07-21 20:37:49
 * @解题思路:
 * 把数组拼接即可
 */

class Solution {
   public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2 * n);
        for (int i = 0; i < n; i++) {
            ans[i] = nums[i];
            ans[i + n] = nums[i];
        }
        return ans;
    }
};