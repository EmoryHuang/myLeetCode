/*
 * @Descroption: 剑指 Offer 42. 连续子数组的最大和
 * @Author: EmoryHuang
 * @Date: 2021-07-04 14:47:43
 * @解题思路:
 * 动态规划
 * 状态转移方程：dp[i] = max(dp[i - 1] + nums[i], nums[i])
 */

class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        int ans = nums[0];
        for (int i = 1; i < n; i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};