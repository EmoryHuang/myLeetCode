'''
Descroption: LeetCode 1994. 好子集的数目
Author: EmoryHuang
Date: 2022-02-22 16:03:24
Method:
动态规划
由于使用的数字有限，因此考虑使用1个二进制位记录每个数字的使用情况
dp[mask] 表示质数使用情况为 mask 时的方案数量
由于方案通过下标来决定，因此需要统计 nums 中每个数字出现的频率
对于 nums 中的每个数字，判断它的因数是否仅包含不同的质数，subset 记录质数使用情况
倒序枚举状态，保证当前选择的状态与前一个状态不会冲突，方案数进行累加
'''


class Solution:
    def numberOfGoodSubsets(self, nums: List[int]) -> int:
        primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]
        mod = 10**9 + 7
        cnts = Counter(nums)

        # dp[mask] 表示质数使用情况为 mask 时的方案数量
        dp = [0] * (1 << len(primes))
        dp[0] = 1 << cnts[1] % mod
        for num, freq in cnts.items():
            if num == 1:
                continue
            # 判断每个数的因数是否仅包含不同的质数
            # subset 记录质数使用情况
            flag, subset = True, 0
            for i, p in enumerate(primes):
                if num % (p**2) == 0:
                    flag = False
                    break
                if num % p == 0:
                    subset |= 1 << i
            if not flag:
                continue

            # 倒序枚举状态
            # 保证当前选择的状态与前一个状态不会冲突，方案数进行累加
            for mask in range((1 << len(primes)) - 1, 0, -1):
                if (mask & subset) == subset:
                    dp[mask] = (dp[mask] + dp[mask ^ subset] * freq) % mod
        ans = sum(dp[1:]) % mod
        return ans
