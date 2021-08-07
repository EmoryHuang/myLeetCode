/*
 * @Descroption: 剑指 Offer II 008. 和大于等于 target 的最短子数组
 * @Author: EmoryHuang
 * @Date: 2021-08-07 14:42:17
 * @Method:
 * 滑动窗口
 * 如果窗口中的和大于 target，则左端点向右移动，并更新最小长度
 */

class Solution {
   public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0;
        int n = nums.size();
        int ans = INT_MAX, sum = 0;
        while (r < n) {
            sum += nums[r++];
            while (sum >= target) {
                ans = min(ans, r - l);
                sum -= nums[l++];
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};