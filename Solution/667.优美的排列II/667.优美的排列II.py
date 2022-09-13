'''
Descroption: LeetCode 667. 优美的排列 II
Author: EmoryHuang
Date: 2022-09-08 09:31:50
Method:
找规律：1,k+1,2,k+1-1,3,k+1-2,...,n
'''


class Solution:
    def constructArray(self, n: int, k: int) -> List[int]:
        ans = []
        for i in range(1, (k + 1) // 2 + 1):
            ans.append(i)
            ans.append(k + 2 - i)
        if k % 2 == 0:
            ans.append(1 + k // 2)
        return ans + [i for i in range(k + 2, n + 1)]
