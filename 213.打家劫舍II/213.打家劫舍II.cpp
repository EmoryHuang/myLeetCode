/*
 * @Descroption: LeetCode 213. 打家劫舍 II
 * @Author: EmoryHuang
 * @Date: 2021-04-15 19:17:36
 * @解题思路: 与 [198. 打家劫舍]类似的动态规划问题
 * 第一个和最后一个不能同时抢，不抢第一个的时候，最后一个可抢可不抢；另一种情况同理
 * 取两种情况中的最大值
 * `dp[i]`表示到第`i`个所偷的最大值，
 * 状态转移方程 `dp[i] = max(dp[i - 2] + nums[i], dp[i - 1])`
 */

class Solution {
   public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0;
        if (len == 1) return nums[0];
        if (len == 2) return max(nums[0], nums[1]);
        vector<int> dp1(len), dp2(len);
        // 不偷第一个
        dp1[0] = 0;
        dp1[1] = nums[1];
        for (int i = 2; i < len; i++) {
            dp1[i] = max(dp1[i - 2] + nums[i], dp1[i - 1]);
        }
        // 不偷最后一个
        dp2[0] = nums[0];
        dp2[1] = max(nums[0], nums[1]);
        for (int i = 2; i < len - 1; i++) {
            dp2[i] = max(dp2[i - 2] + nums[i], dp2[i - 1]);
        }
        return max(dp1[len - 1], dp2[len - 2]);
    }
};