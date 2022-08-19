'''
Descroption: LeetCode 1295. 统计位数为偶数的数字
Author: EmoryHuang
Date: 2021-07-19 18:54:28
解题思路:
遍历数组，计数偶数长度的数量
'''


class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        cnt = 0
        for num in nums:
            if len(str(num)) % 2 == 0:
                cnt += 1
        return cnt
