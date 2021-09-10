/*
 * @Descroption: LeetCode 718. 最长重复子数组
 * @Author: EmoryHuang
 * @Date: 2021-06-25 20:38:00
 * @解题思路:
 * 动态规划
 * dp[i][j]表示以 A[i-1], B[j-1] 结尾的最长重复子数组
 * 状态转移方程：
 * 当 A[i - 1] == B[j - 1] 时，dp[i][j] = dp[i - 1][j - 1] + 1
 * 当 A[i - 1] != B[j - 1] 时，dp[i][j] = 0
 */

class Solution {
   public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        // dp[i][j]表示以 A[i-1], B[j-1] 结尾的最长重复子数组
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        int ans = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    ans = max(ans, dp[i][j]);
                }
        return ans;
    }
};