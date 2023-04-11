'''
Descroption: LeetCode 1534. 统计好三元组
Author: EmoryHuang
Date: 2023-04-06 16:31:50
Method:
简单题，暴力枚举
'''


class Solution:
    def countGoodTriplets(self, arr: List[int], a: int, b: int, c: int) -> int:
        ans = 0
        n = len(arr)
        for i in range(n):
            for j in range(i + 1, n):
                for k in range(j + 1, n):
                    if abs(arr[i] - arr[j]) <= a and abs(arr[j] - arr[k]) <= b and abs(
                            arr[i] - arr[k]) <= c:
                        ans += 1
        return ans