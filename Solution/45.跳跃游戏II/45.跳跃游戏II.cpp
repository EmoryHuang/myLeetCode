/*
 * @Descroption: LeetCode 45. 跳跃游戏 II
 * @Author: EmoryHuang
 * @Date: 2021-05-21 14:43:00
 * @解题思路:
 * 动态规划
 * 遍历数组，每次遍历更新能够到达此位置的最小跳跃次数
 * dp[i]表示到达位置i的最小跳跃次数
 * 若能够从位置j跳到位置i，那么dp[i] = min(dp[i], dp[j] + 1)
 */

class Solution {
   public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < i; j++) {
                if (j + nums[j] >= i)               // 能够从位置j跳到位置i
                    dp[i] = min(dp[i], dp[j] + 1);  // 更新最小跳跃次数
            }
        return dp[n - 1];
    }
};