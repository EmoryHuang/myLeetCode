'''
Descroption: 面试题 17.11. 单词距离
Author: EmoryHuang
Date: 2022-05-27 08:48:24
Method:
一次遍历 + 双指针
记录单词出现的位置，取最短距离
'''


class Solution:
    def findClosest(self, words: List[str], word1: str, word2: str) -> int:
        ans = len(words)
        index1, index2 = -1, -1
        for i, word in enumerate(words):
            if word == word1:
                index1 = i
            elif word == word2:
                index2 = i
            if index1 >= 0 and index2 >= 0:
                ans = min(ans, abs(index1 - index2))
        return ans