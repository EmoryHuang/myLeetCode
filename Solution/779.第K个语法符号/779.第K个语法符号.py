'''
Descroption: LeetCode 779. 第K个语法符号
Author: EmoryHuang
Date: 2021-09-15 19:10:55
Method:
递归
每一行的后半部分正好是前半部分的翻转
'''


class Solution:
    def kthGrammar(self, n: int, k: int) -> int:
        if n == 1:
            return 0
        # 如果 k 在前半段
        if k <= 2**(n - 2):
            return self.kthGrammar(n - 1, k)
        # 如果 k 在后半段
        return self.kthGrammar(n - 1, k - 2**(n - 2)) ^ 1
