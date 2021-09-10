/*
 * @Descroption: LeetCode 1035. 不相交的线
 * @Author: EmoryHuang
 * @Date: 2021-05-21 12:56:59
 * @解题思路:
 * 动态规划
 * dp[i][j]表示nums1的前i个数字和nums2的前j个数字能够绘制的最大连接数
 * 若nums1[i]==nums2[j],则dp[i][j]=dp[i-1][j-1]+1
 * 若nums1[i]!=nums2[j],则dp[i][j]=max(dp[i-1][j],dp[i][j-1])
 */

class Solution {
   public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (nums1[i - 1] == nums2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }
};