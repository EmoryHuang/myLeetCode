'''
Descroption: LeetCode 1652. 拆炸弹
Author: EmoryHuang
Date: 2022-09-24 09:18:15
Method:
暴力遍历
'''


class Solution:

    def decrypt(self, code: List[int], k: int) -> List[int]:
        n = len(code)
        ans = [0] * n
        if k == 0:
            return ans
        if k > 0:
            for i in range(n):
                for j in range(1, k + 1):
                    ans[i] += code[(i + j) % n]
        else:
            for i in range(n):
                for j in range(k, 0):
                    ans[i] += code[(i + j + n) % n]
        return ans
