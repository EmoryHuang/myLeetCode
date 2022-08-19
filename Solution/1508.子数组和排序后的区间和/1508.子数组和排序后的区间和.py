'''
Descroption: LeetCode 1508. 子数组和排序后的区间和
Author: EmoryHuang
Date: 2021-08-11 14:53:24
Method:
暴力遍历
得到所有的子数组的和之后，对数组排序，然后计算指定的下标范围内的元素之和
'''


class Solution:
    def rangeSum(self, nums: List[int], n: int, left: int, right: int) -> int:
        sums = []
        for i in range(n):
            add = 0
            for j in range(i, n):
                add += nums[j]
                sums.append(add)
        sums.sort()
        ans = sum(sums[left - 1:right]) % 1000000007
        return ans