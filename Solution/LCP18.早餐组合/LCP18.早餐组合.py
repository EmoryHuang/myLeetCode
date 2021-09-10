'''
Descroption: LCP 18. 早餐组合
Author: EmoryHuang
Date: 2021-07-08 19:17:08
解题思路:
简单题，直接暴力遍历会超时，可以用排序 + 双指针
'''


class Solution:
    def breakfastNumber(self, staple: List[int], drinks: List[int], x: int) -> int:
        staple.sort()
        drinks.sort()
        n = len(drinks)
        ans, j = 0, n - 1
        for i in range(len(staple)):
            if staple[i] > x:
                break
            while j >= 0 and staple[i] + drinks[j] > x:
                j -= 1
            if j == -1:
                break
            ans += j + 1
            ans %= 1000000007
        return ans
