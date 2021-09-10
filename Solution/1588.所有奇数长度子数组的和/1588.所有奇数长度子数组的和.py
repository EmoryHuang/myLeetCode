'''
Descroption: LeetCode 1588. 所有奇数长度子数组的和
Author: EmoryHuang
Date: 2021-08-29 17:11:33
Method:
方法一：前缀和
前缀和查询区间

方法二：数学
统计每个数字在子数组中会出现多少次
位置i左边奇数个数的方案为(i+1)/2, 右边为 (n-i)/2
位置i左边偶数数个数的方案为i/2, 右边为 (n-i-1)/2
'''


class Solution:
    # 方法一：前缀和
    # def sumOddLengthSubarrays(self, arr: List[int]) -> int:
    #     n = len(arr)
    #     nums = [0] * (n + 1)
    #     for i in range(n):
    #         nums[i + 1] = nums[i] + arr[i]
    #     ans = 0
    #     for l in range(n):
    #         for length in range(1, n + 1 - l, 2):
    #             r = l + length - 1
    #             ans += nums[r + 1] - nums[l]
    #     return ans

    # 方法二：数学
    def sumOddLengthSubarrays(self, arr: List[int]) -> int:
        n, ans = len(arr), 0
        for i, num in enumerate(arr):
            l_odd, r_odd = (i + 1) // 2, (n - i) // 2
            l_even, r_even = i // 2, (n - i - 1) // 2
            l_even += 1
            r_even += 1
            ans += (l_odd * r_odd + l_even * r_even) * num
        return ans
