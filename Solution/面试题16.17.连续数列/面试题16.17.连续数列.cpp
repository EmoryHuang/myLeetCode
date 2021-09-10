/*
 * @Descroption: 面试题 16.17. 连续数列
 * @Author: EmoryHuang
 * @Date: 2021-07-28 19:15:42
 * @Method:
 * 动态规划
 * 状态转移方程：dp[i] = max(dp[i - 1] + nums[i], nums[i])
 */

class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0, ans = nums[0];
        for (int num : nums) {
            pre = max(pre + num, num);
            ans = max(ans, pre);
        }
        return ans;
    }
};