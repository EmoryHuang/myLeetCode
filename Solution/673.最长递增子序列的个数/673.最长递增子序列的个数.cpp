/*
 * @Descroption: LeetCode 673. 最长递增子序列的个数
 * @Author: EmoryHuang
 * @Date: 2021-09-20 19:12:50
 * @Method:
 * 动态规划
 * 在传统最长递增子序列的基础上增加变量
 * dp[i] 表示以 nums[i] 结尾的最长递增子序列的长度
 * cnt[i] 表示以 nums[i] 结尾的最长递增子序列的个数
 * 对 dp[i] == dp[j] + 1 有，cnt[i] += cnt[j]
 */

class Solution {
   public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        // dp[i] 表示以 nums[i] 结尾的最长递增子序列的长度
        // cnt[i] 表示以 nums[i] 结尾的最长递增子序列的个数
        vector<int> dp(n), cnt(n);
        int len = 1;
        for (int i = 0; i < n; i++) {
            dp[i] = cnt[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    } else if (dp[i] == dp[j] + 1)
                        cnt[i] += cnt[j];  // 累积
                }
            }
            len = max(len, dp[i]);  // 记录最长子序列长度
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
            if (dp[i] == len) ans += cnt[i];
        return ans;
    }
};