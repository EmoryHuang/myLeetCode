'''
Descroption: LeetCode 1437. 是否所有 1 都至少相隔 k 个元素
Author: EmoryHuang
Date: 2021-06-05 15:58:00
解题思路:
遍历数组，记录相邻两个 1 之间的距离，若小于 k 则返回 false
'''


class Solution:
    def kLengthApart(self, nums: List[int], k: int) -> bool:
        pre = -1  # 前一个1的位置
        for i, num in enumerate(nums):
            if num == 1:
                if pre != -1 and (i - pre - 1) < k:
                    return False
                pre = i
        return True
