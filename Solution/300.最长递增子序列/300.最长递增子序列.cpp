/*
 * @Descroption: LeetCode 300. 最长递增子序列
 * @Author: EmoryHuang
 * @Date: 2021-03-25 14:28:36
 * @解题思路:
 * 动态规划问题，`dp[i]` 表示以 `nums[i]` 结尾的最长上升子序列的长度
 * 位置 i 的最长升序子序列等于 j 从 0 到 i-1 各个位置的最长升序子序列 + 1 的最大值。
 * 转移方程： `dp[i] = max(dp[i], dp[j] + 1)`
 */

class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp(len, 1);  // 初始为1
        int ans = dp[0];
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {  //寻找 i 之前小于 nums[i] 的数
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[j] + 1, dp[i]);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};