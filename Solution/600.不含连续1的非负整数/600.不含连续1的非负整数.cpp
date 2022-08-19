/*
 * @Descroption: LeetCode 600. 不含连续1的非负整数
 * @Author: EmoryHuang
 * @Date: 2021-09-11 18:33:50
 * @Method:
 * 动态规划
 * 计算不包含连续 1 的从根结点到叶结点的路径数量时，
 * 可以不断地将字典树拆分为根结点为 0 的满二叉树和根结点不定的完全二叉树
 *
 * dp[i] 表示从低位到高位，前 i 个二进制数能产生的合法数字
 * 对于高度为 i，根节点为 0 的01字典树来说
 * 显然有 dp[i][0] = dp[i-1][0] + dp[i-1][1]，即左右子树上满足条件的数量
 * 同时由于不含连续1，有 dp[i-1][1] = dp[i-2][0]
 * 因此可以得到状态转移方程：dp[i] = dp[i - 1] + dp[i - 2]
 */

class Solution {
   public:
    int findIntegers(int n) {
        // dp[i] 表示从低位到高位，前 i 个二进制数能产生的合法数字
        vector<int> dp(31);
        dp[0] = 1;
        dp[1] = 1;
        // 对于高度为 i，根节点为 0 的01字典树来说
        // 显然有 dp[i][0] = dp[i-1][0] + dp[i-1][1]，即左右子树上满足条件的数量
        // 同时由于不含连续1，有 dp[i-1][1] = dp[i-2][0]
        // 因此可以得到状态转移方程：dp[i] = dp[i - 1] + dp[i - 2]
        for (int i = 2; i < 31; i++) dp[i] = dp[i - 1] + dp[i - 2];
        int pre = 0, ans = 0;
        for (int i = 29; i >= 0; i--) {
            int cur = (1 << i) & n;
            if (cur) {                // 当前位为 1，无左子树
                ans += dp[i + 1];     // 加上满二叉树的情况
                if (pre == 1) break;  // 上一层为 1
                pre = 1;
            } else {  // 当前位为 0，无右子树
                pre = 0;
            }
            if (i == 0) ans++;  // 为 0 的情况
        }
        return ans;
    }
};