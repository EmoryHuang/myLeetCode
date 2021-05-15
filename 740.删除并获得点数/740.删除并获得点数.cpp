/*
 * @Descroption: LeetCode 740. 删除并获得点数
 * @Author: EmoryHuang
 * @Date: 2021-05-05 20:24:36
 * @解题思路:
 * 记元素 `x` 在数组中出现的次数为 `c`，用数组 `count` 记录数组 `nums` 中元素出现的次数。
 * 若选择了 `x`，则可以获取 `sum[x]` 的点数，且无法再选择 `x-1` 和 `x+1`，
 * 这就转换成了 [198. 打家劫舍]
 * 使用动态规划的方法，状态转移方程为
 * `dp[i] = max(dp[i - 1], dp[i - 2] + count[i] * (i))`
 * `dp [0] = 0,dp[1] = count[1]`
 */

class Solution {
   public:
    int deleteAndEarn(vector<int>& nums) {
        int m = *max_element(nums.begin(), nums.end());  //数组中的最大元素
        vector<int> dp(m + 1), count(m + 1);
        for (int num : nums) count[num]++;  //记录每个数字出现的次数
        dp[1] = count[1];
        for (int i = 2; i <= m; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + count[i] * (i));
        }
        return dp[m];
    }
};