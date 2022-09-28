'''
Descroption: LeetCode 1636. 按照频率将数组升序排序
Author: EmoryHuang
Date: 2022-09-19 09:19:42
Method:
使用哈希表记录元素数量，之后再排序
'''


class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
        return sorted(nums, key=lambda x: (nums.count(x), -x))
