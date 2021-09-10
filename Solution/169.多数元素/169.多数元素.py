'''
Descroption: LeetCode 169. 多数元素
Author: EmoryHuang
Date: 2021-07-11 14:33:18
解题思路:
方法一：哈希表
使用一个哈希表记录元素的数量
方法二：摩尔投票
摩尔投票：每次将两个不同的元素进行「抵消」，如果最后有元素剩余，则「可能」为元素个数大于总数一半的那个
之后再进行一次遍历，检查这个「可能」的主要元素 x 的出现次数是否超过总数一半
'''


class Solution:
    # 方法一：哈希表
    # def majorityElement(self, nums: List[int]) -> int:
    #     hash = defaultdict(int)
    #     for num in nums:
    #         hash[num] += 1
    #         if hash[num] >= len(nums) // 2:
    #             return num
    #     return 0

    # 方法二：摩尔投票
    def majorityElement(self, nums: List[int]) -> int:
        ans = cnt = 0
        for i, num in enumerate(nums):
            if cnt == 0:
                ans = num
            if ans == num:
                cnt += 1
            else:
                cnt -= 1
        cnt = 0
        for num in nums:
            if ans == num:
                cnt += 1
        return ans if cnt > len(nums) // 2 else 0