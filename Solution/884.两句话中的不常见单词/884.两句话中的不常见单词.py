'''
Descroption: LeetCode 884. 两句话中的不常见单词
Author: EmoryHuang
Date: 2021-08-26 18:37:15
Method:
简单题，哈希表计数，寻找只出现一次的单词
'''


class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        s = s1.split(' ') + s2.split(' ')
        return [word for word in s if s.count(word) == 1]
