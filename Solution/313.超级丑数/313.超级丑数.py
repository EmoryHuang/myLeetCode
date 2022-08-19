'''
Descroption: LeetCode 313. 超级丑数
Author: EmoryHuang
Date: 2021-08-09 13:42:25
Method:
方法一：最小堆
每次取出堆顶元素 x，则 x 是堆中最小的超级丑数
对于数组 primes 的任意质数 p，px 也是超级丑数，因此将乘积加入堆
重复操作n次即是第n个超级丑数
方法二：动态规划
dp[i] 表示第i个超级丑数
使用m个指针分别指向dp[i]的primes[i]倍数，若遍历到则跳过
'''


class Solution:
    # 方法一：最小堆
    # def nthSuperUglyNumber(self, n: int, primes: List[int]) -> int:
    #     heap = [1]
    #     vis = {1}
    #     for i in range(n):
    #         ugly = heapq.heappop(heap)
    #         for prime in primes:
    #             next = ugly * prime
    #             if next not in vis:
    #                 vis.add(next)
    #                 heapq.heappush(heap, next)
    #     return ugly

    # 方法二：动态规划
    def nthSuperUglyNumber(self, n: int, primes: List[int]) -> int:
        m = len(primes)
        # dp[i] 表示第i个超级丑数
        dp = [0] * (n + 1)
        dp[1] = 1
        # p[j] 表示 j 个指针
        p = [1] * m
        for i in range(2, n + 1):
            minn = min(primes[j] * dp[p[j]] for j in range(m))
            dp[i] = minn
            for j in range(m):
                if primes[j] * dp[p[j]] == minn:
                    p[j] += 1
        return dp[n]
