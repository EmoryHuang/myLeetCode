'''
Descroption: 剑指 Offer 49. 丑数
Author: EmoryHuang
Date: 2021-07-04 15:01:49
解题思路:
通过遍历判断丑数会超时

使用动态规划方法，设置三个指针`p2`，`p3`，`p5`，令`dp[0]=1`
`p2`，`p3`，`p5`分别指向`dp[i]`的 2 倍，3 倍，5 倍数，
若遍历到则跳过，`dp[n-1]`即为所求
'''


class Solution:
    def nthUglyNumber(self, n: int) -> int:
        # 维护三个指针
        p2 = p3 = p5 = 0
        dp = [0] * n
        dp[0] = 1
        for i in range(1, n):
            n2, n3, n5 = dp[p2] * 2, dp[p3] * 3, dp[p5] * 5
            dp[i] = min(n2, n3, n5)
            if dp[i] == n2:
                p2 += 1
            if dp[i] == n3:
                p3 += 1
            if dp[i] == n5:
                p5 += 1
        return dp[n - 1]
