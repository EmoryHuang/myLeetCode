/*
 * @Descroption: LeetCode 689. 三个无重叠子数组的最大和
 * @Author: EmoryHuang
 * @Date: 2021-12-08 19:58:40
 * @Method:
 * 方法一：滑动窗口
 * 同时滑动三个窗口，并记录最大和
 *
 * 方法二：动态规划
 * dp[i][j] 表示前 i 个元素中，j 个子数组的最大和
 * 若最优方案中包含 num[i], 只能在 [0, i - k] 中选 j - 1 个子数组
 * 若最优方案中不包含 num[i], dp[i][j] = dp[i - 1][j]
 * 状态转移方程：dp[i][j] = max(dp[i - 1][j], dp[i - k][j - 1] + sum[i - k + 1] - sum[i + 1])
 * */

class Solution {
   public:
    // 方法一：滑动窗口
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int sum1 = 0, max_sum1 = 0, max_sum1_idx = 0;
        int sum2 = 0, max_sum12 = 0, max_sum12_idx1 = 0, max_sum12_idx2 = 0;
        int sum3 = 0, max_sum123 = 0;
        vector<int> ans;
        for (int i = 2 * k; i < nums.size(); i++) {
            sum1 += nums[i - 2 * k];
            sum2 += nums[i - k];
            sum3 += nums[i];
            if (i >= 3 * k - 1) {
                if (sum1 > max_sum1) {
                    max_sum1 = sum1;
                    max_sum1_idx = i - 3 * k + 1;
                }
                if (sum2 + max_sum1 > max_sum12) {
                    max_sum12 = sum2 + max_sum1;
                    max_sum12_idx1 = max_sum1_idx;
                    max_sum12_idx2 = i - 2 * k + 1;
                }
                if (sum3 + max_sum12 > max_sum123) {
                    max_sum123 = sum3 + max_sum12;
                    ans = {max_sum12_idx1, max_sum12_idx2, i - k + 1};
                }
                sum1 -= nums[i - 3 * k + 1];
                sum2 -= nums[i - 2 * k + 1];
                sum3 -= nums[i - k + 1];
            }
        }
        return ans;
    }

    // 方法二：动态规划
    // vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     vector<int> sum(n + 1);
    //     for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + nums[i - 1];
    //     // dp[i][j] 表示前 i 个元素中，j 个子数组的最大和
    //     vector<vector<int>> dp(n + 2, vector<int>(4));
    //     // 逆序遍历，因为后面的子数组的最大和要用到前面的子数组的最大和
    //     for (int i = n - k + 1; i >= 1; i--) {
    //         for (int j = 1; j < 4; j++) {
    //             // 若最优方案中包含 num[i], 只能在 [0, i - k] 中选 j - 1 个子数组
    //             // 若最优方案中不包含 num[i], dp[i][j] = dp[i - 1][j]
    //             dp[i][j] = max(dp[i + 1][j], dp[i + k][j - 1] + sum[i + k - 1] - sum[i - 1]);
    //         }
    //     }
    //     vector<int> ans(3);
    //     int i = 1, j = 3, idx = 0;
    //     while (j > 0) {
    //         if (dp[i + 1][j] > dp[i + k][j - 1] + sum[i + k - 1] - sum[i - 1])
    //             i++;
    //         else {
    //             ans[idx++] = i - 1;
    //             i += k;
    //             j--;
    //         }
    //     }
    //     return ans;
    // }
};