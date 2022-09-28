'''
Descroption: LeetCode 面试题 17.09. 第 k 个数
Author: EmoryHuang
Date: 2022-09-28 09:24:50
Method:
三指针
由题意，某一个数一定由前一个数×3,5,7得到，并且为这三个数的最小值
定义指针num3, num5, num7，表示下一个数是当前指针指向的数乘以对应的质因数
'''


class Solution:

    def getKthMagicNumber(self, k: int) -> int:
        dp = [0] * k
        dp[0] = 1
        num3, num5, num7 = 0, 0, 0
        for i in range(1, k):
            dp[i] = min(dp[num3] * 3, min(dp[num5] * 5, dp[num7] * 7))
            if dp[i] == dp[num3] * 3:
                num3 += 1
            if dp[i] == dp[num5] * 5:
                num5 += 1
            if dp[i] == dp[num7] * 7:
                num7 += 1
        return dp[k - 1]
