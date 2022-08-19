'''
Descroption: LeetCode 318. 最大单词长度乘积
Author: EmoryHuang
Date: 2021-11-17 09:12:58
Method:
位运算
使用 bits 记录每个字母是否出现
然后遍历 mask 使用 & 运算，若为 0 则说明没有重复字母
'''


class Solution:
    def maxProduct(self, words: List[str]) -> int:
        n = len(words)
        mask = []
        for i, word in enumerate(words):
            # 使用 bits 记录每个字母是否出现
            bits = 0
            for c in word:
                bits |= 1 << (ord(c) - ord('a'))
            mask.append(bits)
        ans = 0
        for i in range(n):
            for j in range(i + 1, n):
                # & 运算，若为 0 则说明没有重复字母
                if not (mask[i] & mask[j]):
                    ans = max(ans, len(words[i]) * len(words[j]))
        return ans
