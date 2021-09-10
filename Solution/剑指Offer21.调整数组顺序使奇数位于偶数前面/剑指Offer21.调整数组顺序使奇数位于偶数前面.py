'''
Descroption: 剑指 Offer 21. 调整数组顺序使奇数位于偶数前面
Author: EmoryHuang
Date: 2021-06-30 20:35:00
解题思路:
维护两个指针
方法一：快慢指针
fast 遍历数组元素，slow 记录奇数位置
方法二：头尾指针
'''


class Solution:
    # 方法一：快慢指针
    def exchange(self, nums: List[int]) -> List[int]:
        slow = fast = 0
        while fast < len(nums):
            if nums[fast] & 1:  # 如果是奇数
                nums[slow], nums[fast] = nums[fast], nums[slow]
                slow += 1
            fast += 1
        return nums

    # 方法二：头尾指针
    # def exchange(self, nums: List[int]) -> List[int]:
    #     l, r = 0, len(nums) - 1
    #     while l < r:
    #         while l < r and nums[l] & 1:  # 如果是奇数
    #             l += 1
    #         while l < r and not nums[r] & 1:
    #             r -= 1
    #         nums[l], nums[r] = nums[r], nums[l]
    #         l += 1
    #         r -= 1
    #     return nums
