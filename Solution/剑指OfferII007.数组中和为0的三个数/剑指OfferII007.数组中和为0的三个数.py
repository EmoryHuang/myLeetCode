'''
Descroption: 剑指 Offer II 007. 数组中和为 0 的三个数
Author: EmoryHuang
Date: 2021-08-04 19:25:55
Method:
三指针，排序
对数组进行排序，然后设置三个指针分别执行元素
注意跳过重复数字
'''


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        if not nums or n < 3:
            return []
        nums.sort()
        if nums[0] > 0:
            return []
        ans = []
        for i in range(n):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            j, k = i + 1, n - 1
            while j < k:
                if nums[i] + nums[j] + nums[k] > 0:
                    k -= 1
                elif nums[i] + nums[j] + nums[k] < 0:
                    j += 1
                else:
                    ans.append([nums[i], nums[j], nums[k]])
                    while j < k and nums[j] == nums[j + 1]:
                        j += 1
                    while j < k and nums[k] == nums[k - 1]:
                        k -= 1
                    j += 1
                    k -= 1
        return ans