/*
 * @Descroption: LeetCode 264. 丑数 II
 * @Author: EmoryHuang
 * @Date: 2021-04-11 17:04:36
 * @解题思路:
 * 通过遍历判断丑数会超时
 *
 * 使用动态规划方法，设置三个指针`p2`，`p3`，`p5`，令`dp[0]=1`
 * `p2`，`p3`，`p5`分别指向`dp[i]`的 2 倍，3 倍，5 倍数，
 * 若遍历到则跳过，`dp[n-1]`即为所求
 */

class Solution {
   public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;
        for (int i = 1; i < n; i++) {
            int num2 = dp[p2] * 2, num3 = dp[p3] * 3, num5 = dp[p5] * 5;
            dp[i] = min(min(num2, num3), num5);
            if (dp[i] == num2) p2++;  // 跳过
            if (dp[i] == num3) p3++;
            if (dp[i] == num5) p5++;
        }
        return dp[n - 1];
    }
};