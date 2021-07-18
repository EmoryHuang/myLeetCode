'''
Descroption: 面试题 16.10. 生存人数
Author: EmoryHuang
Date: 2021-07-18 15:17:29
解题思路:
差分思想
统计每年变化的人数
'''


class Solution:
    def maxAliveYear(self, birth: List[int], death: List[int]) -> int:
        cnt = [0] * 101
        for i in range(len(birth)):
            x, y = birth[i] - 1900, death[i] - 1900
            cnt[x] += 1
            if y + 1 <= 100:
                cnt[y + 1] -= 1
        sum, max, ans = 0, -1, 0
        for i in range(101):
            sum += cnt[i]
            if sum > max:
                max = sum
                ans = i + 1900
        return ans
