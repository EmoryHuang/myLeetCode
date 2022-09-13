'''
Descroption: LeetCode 1470. 重新排列数组
Author: EmoryHuang
Date: 2022-08-29 09:39:19
Method:
利用Python特性
'''


class Solution:
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        nums[::2], nums[1::2] = nums[:n], nums[n:]
        return nums