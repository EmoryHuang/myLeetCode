'''
Descroption: LeetCode 1238. 循环码排列
Author: EmoryHuang
Date: 2023-02-23 14:16:40
Method:
公式法
G(i) = i ^ (i/2)，再将结果与 start 做异或
'''


class Solution:
    def circularPermutation(self, n: int, start: int) -> List[int]:
        ans = [0] * (1 << n)
        for i in range(1 << n):
            ans[i] = (i >> 1) ^ i ^ start
        return ans
