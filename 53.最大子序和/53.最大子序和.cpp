/*
 * @Descroption: LeetCode 53. 最大子序和
 * @Author: EmoryHuang
 * @Date: 2021-03-18 20:22:36
 * @解题思路: 动态规划
 * dp [i] 代表着以 nums [i] 结尾的最大的子序列和
 * dp[i] = max(dp[i - 1] + nums[i], nums[i]);
 */

class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size(), sum = INT_MIN;
        vector<int> dp(len);
        dp[0] = nums[0];
        for (int i = 1; i < len; i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            if (dp[i] > sum) sum = dp[i];
        }
        return max(dp[0], sum);
    }
};