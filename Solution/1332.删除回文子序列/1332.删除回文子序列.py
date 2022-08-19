'''
Descroption: LeetCode 1332. 删除回文子序列
Author: EmoryHuang
Date: 2022-01-22 15:11:09
Method:
模拟
因为只包含a和b，因此最多只需要删除 2 次即可删除所有的字符
'''


class Solution:
    def removePalindromeSub(self, s: str) -> int:
        return 1 if s == s[::-1] else 2
