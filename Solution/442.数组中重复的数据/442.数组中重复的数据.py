'''
Descroption: LeetCode 442. 数组中重复的数据
Author: EmoryHuang
Date: 2022-05-08 10:44:08
Method:
方法一: 交换位置
由于给定的 n 个数都在 [1, n] 的范围内
对数组进行遍历, 当遍历到位置 i 时, nums[i] 应该被放在位置 nums[i] - 1
因此我们交换 num[i] 和 nums[nums[i] - 1] 即可，直到待交换的两个元素相等为止

方法二: 正负号标识
对 nums[i] 添加负号表示已经出现过
遍历到位置 i 时，考虑 nums[nums[i] - 1] 的正负性
'''


class Solution:
    # 方法一: 交换位置
    # def findDuplicates(self, nums: List[int]) -> List[int]:
    #     for i in range(len(nums)):
    #         while nums[i] != nums[nums[i] - 1]:
    #             nums[nums[i] - 1], nums[i] = nums[i], nums[nums[i] - 1]
    #     return [num for i, num in enumerate(nums) if num - 1 != i]

    # 方法二: 正负号标识
    def findDuplicates(self, nums: List[int]) -> List[int]:
        ans = []
        for x in nums:
            x = abs(x)
            if nums[x - 1] > 0:
                nums[x - 1] = -nums[x - 1]
            else:
                ans.append(x)
        return ans
