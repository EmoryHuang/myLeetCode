'''
Descroption: LeetCode 1408. 数组中的字符串匹配
Author: EmoryHuang
Date: 2021-06-23 12:50:00
解题思路:
暴力，遍历每个元素，在其他元素中查找是否为子串
'''


class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        ans = []
        for i, word in enumerate(words):
            if word in ' '.join(words[:i] + words[i + 1:]):
                ans.append(word)
        return ans
