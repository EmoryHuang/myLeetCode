'''
Descroption: LeetCode 455. 分发饼干
Author: EmoryHuang
Date: 2021-06-08 19:40:00
解题思路:
贪心思想，对 s 和 g 进行排序，然后判断当前饼干是否可以满足当前孩子的需求
'''


class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        ans, cookies = 0, 0
        g.sort()
        s.sort()
        while cookies < len(s) and ans < len(g):
            # 当前饼干可以满足当前孩子的需求
            if s[cookies] >= g[ans]:
                ans += 1
            cookies += 1
        return ans
