'''
Descroption: LeetCode 581. 最短无序连续子数组
Author: EmoryHuang
Date: 2021-08-03 11:04:33
Method:
方法一：排序
将原数组排序之后，比较前半部分和后半部分有序部分的长度
方法二：双指针
我们可以通过寻找无序连续子数组中的最大值和最小值确定左右边界
'''


class Solution:
    # 方法一：排序
    # def findUnsortedSubarray(self, nums: List[int]) -> int:
    #     n = len(nums)
    #     copy = nums
    #     nums = sorted(nums)
    #     if copy == nums: return 0
    #     l, r = 0, n - 1
    #     while nums[l] == copy[l]:
    #         l += 1
    #     while nums[r] == copy[r]:
    #         r -= 1
    #     return r - l + 1

    # 方法二：双指针
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        l, r = -1, -1
        minn, maxn = float('inf'), float('-inf')
        for i in range(n):
            # 寻找无序子数组的右边界
            if nums[i] >= maxn:
                # 升序，更新maxn
                maxn = nums[i]
            else:
                # 降序，更新边界
                r = i
            # 寻找无序子数组的左边界
            if nums[n - i - 1] <= minn:
                minn = nums[n - i - 1]
            else:
                l = n - i - 1
        if l == -1:
            return 0
        return r - l + 1
