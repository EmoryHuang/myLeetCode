'''
Descroption: LeetCode 949. 给定数字能组成的最大时间
Author: EmoryHuang
Date: 2021-06-04 15:14:00
解题思路:
暴力遍历
'''


class Solution:
    def largestTimeFromDigits(self, arr: List[int]) -> str:
        maxt = 0
        ans = ''
        for h1, h2, m1, m2 in permutations(arr):
            hour = h1 * 10 + h2
            min = m1 * 10 + m2
            time = hour * 60 + min
            if hour < 24 and min < 60 and time >= maxt:
                ans = "{}{}:{}{}".format(h1, h2, m1, m2)
                maxt = time
        return ans
