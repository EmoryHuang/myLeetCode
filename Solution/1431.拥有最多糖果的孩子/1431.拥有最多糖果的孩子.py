'''
Descroption: LeetCode 1431. 拥有最多糖果的孩子
Author: EmoryHuang
Date: 2021-10-20 19:31:33
Method:
简单题，遍历数组与最大值比较
'''


class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        maxc = max(candies)
        return [num + extraCandies >= maxc for num in candies]