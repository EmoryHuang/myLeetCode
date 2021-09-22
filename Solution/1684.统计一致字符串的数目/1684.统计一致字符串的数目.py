'''
Descroption: LeetCode 1684. 统计一致字符串的数目
Author: EmoryHuang
Date: 2021-09-22 16:32:12
Method:
简单题，依次判断每个单词所含的字符是否在 allowed 中
'''


class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        ans = 0
        for word in words:
            for c in word:
                if c not in allowed:
                    break
            else:
                ans += 1
        return ans