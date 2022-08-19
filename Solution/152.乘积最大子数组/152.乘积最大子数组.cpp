/*
 * @Descroption: LeetCode 152. 乘积最大子数组
 * @Author: EmoryHuang
 * @Date: 2021-07-11 14:00:48
 * @解题思路:
 * 遍历数组时计算当前最大值，不断更新
 * 由于存在负数，那么会导致最大的变最小的，最小的变最大的。因此还需要维护当前最小值
 */

class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        int dpmax, dpmin, ans;
        dpmax = dpmin = ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int tmpmax = dpmax, tmpmin = dpmin;
            dpmax = max(nums[i], max(nums[i] * tmpmax, nums[i] * tmpmin));
            dpmin = min(nums[i], min(nums[i] * tmpmax, nums[i] * tmpmin));
            ans = max(ans, dpmax);
        }
        return ans;
    }
};