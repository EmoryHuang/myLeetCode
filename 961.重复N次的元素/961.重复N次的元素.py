'''
Descroption: LeetCode 961. 重复 N 次的元素
Author: EmoryHuang
Date: 2021-06-28 14:27:00
解题思路:
简单题，哈希表计数
'''


class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        hash = defaultdict(int)
        for num in nums:
            hash[num] += 1
            if hash[num] > 1:  # 有 2 个即为所求数
                return num
