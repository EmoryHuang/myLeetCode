'''
Descroption: LeetCode 1768. 交替合并字符串
Author: EmoryHuang
Date: 2022-10-23 10:40:40
Method:
双指针，分别记录两个字符串位置，交替遍历
'''


class Solution:

    def mergeAlternately(self, word1: str, word2: str) -> str:
        m, n = len(word1), len(word2)
        i, j = 0, 0
        ans = []
        while i < m or j < n:
            if i < m:
                ans.append(word1[i])
                i += 1
            if j < n:
                ans.append(word2[j])
                j += 1
        return ''.join(ans)
