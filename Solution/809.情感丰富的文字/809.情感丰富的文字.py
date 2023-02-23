'''
Descroption: LeetCode 809. 情感丰富的文字
Author: EmoryHuang
Date: 2022-11-25 09:25:55
Method:
双指针，依次判断每个字符是否满足条件
指针 i 和 j 初始时分别指向字符串 s 和 word 的首个位置
'''


class Solution:
    def expressiveWords(self, s: str, words: List[str]) -> int:
        def check(s, word):
            m, n = len(s), len(word)
            if n > m:
                return False
            i = j = 0
            while i < m and j < n:
                if s[i] != word[j]:
                    return False
                k = i
                while k < m and s[k] == s[i]:
                    k += 1
                cnt1 = k - i
                i, k = k, j
                while k < n and word[k] == word[j]:
                    k += 1
                cnt2 = k - j
                j = k
                if cnt1 < cnt2 or (cnt1 < 3 and cnt1 != cnt2):
                    return False
            return i == m and j == n

        return sum([check(s, word) for word in words])