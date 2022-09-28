/*
 * @Descroption: LeetCode 面试题 17.09. 第 k 个数
 * @Author: EmoryHuang
 * @Date: 2022-09-28 09:28:42
 * @Method:
 * 三指针
 * 由题意，某一个数一定由前一个数×3,5,7得到，并且为这三个数的最小值
 * 定义指针num3, num5, num7，表示下一个数是当前指针指向的数乘以对应的质因数
 */

class Solution {
    public int getKthMagicNumber(int k) {
        int[] dp = new int[k];
        dp[0] = 1;
        int num3 = 0, num5 = 0, num7 = 0;
        for (int i = 1; i < k; i++) {
            dp[i] = Math.min(dp[num3] * 3, Math.min(dp[num5] * 5, dp[num7] * 7));
            if (dp[i] == dp[num3] * 3)
                num3++;
            if (dp[i] == dp[num5] * 5)
                num5++;
            if (dp[i] == dp[num7] * 7)
                num7++;
        }
        return dp[k - 1];
    }
}