'''
Descroption: LeetCode 788. 旋转数字
Author: EmoryHuang
Date: 2022-09-25 11:10:25
Method:
根据题意，好数中不能有 3,4,7，且至少包含 2,5,6,9 中的一个
遍历[1,n]，判断每个数字是否是好数即可
'''


class Solution:
    def rotatedDigits(self, n: int) -> int:
        ans = 0
        for num in range(1, n + 1):
            flag = False
            while num:
                t, num = num % 10, num // 10
                if t in [2, 5, 6, 9]:
                    flag = True
                elif t in [3, 4, 7]:
                    flag = False
                    break
            ans += 1 if flag else 0
        return ans