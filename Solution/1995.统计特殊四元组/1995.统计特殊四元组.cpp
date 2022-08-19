/*
 * @Descroption: LeetCode 1995. 统计特殊四元组
 * @Author: EmoryHuang
 * @Date: 2021-12-29 09:20:35
 * @Method:
 * 方法一: 暴力
 * 简单题，由于 N 的范围很小，可以直接暴力遍历
 *
 * 方法二: 背包问题
 * 定义 dp[i][j][k] 为考虑前 i 个物品，凑成数值恰好 j，使用个数恰好为 k 的方案数
 * 状态转移方程
 * 如果不加入物品 nums[i-1], 那么 f[i][j][k] = f[i - 1][j][k]
 * 如果加入物品 nums[i-1], 那么 f[i][j][k] = f[i - 1][j - nums[i - 1]][k - 1]
 *
 * 空间优化: 通过倒序遍历降低空间复杂度
 * */

class Solution {
   public:
    // 方法一: 暴力
    // int countQuadruplets(vector<int>& nums) {
    //     int n = nums.size(), ans = 0;
    //     for (int a = 0; a < n; a++) {
    //         for (int b = a + 1; b < n; b++) {
    //             for (int c = b + 1; c < n; c++) {
    //                 for (int d = c + 1; d < n; d++) {
    //                     if (nums[a] + nums[b] + nums[c] == nums[d]) ans++;
    //                 }
    //             }
    //         }
    //     }
    //     return ans;
    // }

    // 方法二: 背包问题
    // int countQuadruplets(vector<int>& nums) {
    //     int n = nums.size(), ans = 0;
    //     // dp[i][j][k] 为考虑前 i 个物品，凑成数值恰好 j，使用个数恰好为 k 的方案数
    //     vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(101, vector<int>(4, 0)));
    //     dp[0][0][0] = 1;
    //     for (int i = 1; i <= n; i++) {
    //         for (int j = 0; j < 101; j++) {
    //             for (int k = 0; k < 4; k++) {
    //                 dp[i][j][k] += dp[i - 1][j][k];
    //                 // 如果还能放下第 i 个物品
    //                 if (j - nums[i - 1] >= 0 && k - 1 >= 0) {
    //                     dp[i][j][k] += dp[i - 1][j - nums[i - 1]][k - 1];
    //                 }
    //             }
    //         }
    //     }
    //     for (int i = 3; i <= n; i++) ans += dp[i][nums[i - 1]][3];
    //     return ans;
    // }

    // 方法三: 背包问题(空间优化)
    int countQuadruplets(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        // dp[i][j][k] 为考虑前 i 个物品，凑成数值恰好 j，使用个数恰好为 k 的方案数
        vector<vector<int>> dp(101, vector<int>(4, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            ans += dp[nums[i - 1]][3];
            for (int j = 100; j >= 0; j--) {
                for (int k = 0; k < 4; k++) {
                    // 如果还能放下第 i 个物品
                    if (j - nums[i - 1] >= 0 && k - 1 >= 0) {
                        dp[j][k] += dp[j - nums[i - 1]][k - 1];
                    }
                }
            }
        }
        return ans;
    }
};