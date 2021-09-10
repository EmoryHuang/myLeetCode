/*
 * @Descroption: LeetCode 1884. 鸡蛋掉落-两枚鸡蛋
 * @Author: EmoryHuang
 * @Date: 2021-07-20 19:42:58
 * @解题思路:
 * 动态规划
 * dp[i]表示楼层 i 处第一枚鸡蛋没碎时的最小操作数量
 * 如果第一枚鸡蛋在 j 层碎了，那么仅剩一枚鸡蛋，这时确定 f 就需要从第 1 层逐层向上扔到 j 层
 * 如果第一枚鸡蛋在 j 层没碎，那么需要考虑 i-j 层有两枚鸡蛋时的操作次数，再加上当前这次操作
 */

class Solution {
   public:
    int twoEggDrop(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= i; j++) dp[i] = min(dp[i], max(j, dp[i - j] + 1));
        return dp[n];
    }
};