/*
 * @Descroption: LeetCode 446. 等差数列划分 II - 子序列
 * @Author: EmoryHuang
 * @Date: 2021-08-11 14:34:16
 * @Method:
 * 动态规划 + 哈希表
 * dp[i][d] 表示以 nums[i] 结尾的，公差为 d 的等差数列个数
 * 状态转移方程：dp[i][d] += dp[j][d] + 1
 */

class Solution {
   public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        // dp[i] 的每个元素均为哈希表 {d: cnt}
        // d 表示等差数列的差值
        // cnt 表示以 nums[i] 结尾的，公差为 d 的等差数列个数
        vector<unordered_map<long long, int>> dp(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                // 计算 nums[i] 和 nums[j] 之间的差值
                long long d = 1LL * nums[i] - nums[j];
                // 以 nums[j] 结尾的，公差为 d 的等差数列个数
                int cnt = dp[j][d];
                ans += cnt;
                // 因为 nums[i] 和 nums[j] 的差值也为 d，所以数量加 1
                dp[i][d] += cnt + 1;
            }
        }
        return ans;
    }
};