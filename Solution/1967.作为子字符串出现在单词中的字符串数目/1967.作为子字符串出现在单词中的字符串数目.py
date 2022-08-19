'''
Descroption: LeetCode 1967. 作为子字符串出现在单词中的字符串数目
Author: EmoryHuang
Date: 2021-11-04 19:45:55
Method:
简单题，遍历查看字符是否在字符串中出现
'''


class Solution:
    def numOfStrings(self, patterns: List[str], word: str) -> int:
        ans = 0
        for pattern in patterns:
            if pattern in word:
                ans += 1
        return ans