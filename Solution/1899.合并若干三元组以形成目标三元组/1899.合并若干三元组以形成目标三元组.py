'''
Descroption: LeetCode 1899. 合并若干三元组以形成目标三元组
Author: EmoryHuang
Date: 2021-11-04 20:41:50
Method:
贪心
将数组中每个数都小于 target 的数全部进行合并，比较是否与 target 相同
'''


class Solution:
    def mergeTriplets(self, triplets: List[List[int]], target: List[int]) -> bool:
        cur = [0] * 3
        for a, b, c in triplets:
            if a <= target[0] and b <= target[1] and c <= target[2]:
                cur[0] = max(cur[0], a)
                cur[1] = max(cur[1], b)
                cur[2] = max(cur[2], c)
        return cur == target