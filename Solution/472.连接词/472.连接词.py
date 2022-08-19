'''
Descroption: LeetCode 472. 连接词
Author: EmoryHuang
Date: 2021-12-28 12:09:18
Method:
方法一: 字典树
对于每个非空单词，判断该单词是不是连接词，
如果是连接词则将该单词加入结果数组，如果不是连接词则将该单词加入字典树

判断单词是不是连接词: 
    从单词的第一个字符开始，在字典树中依次搜索每个字符对应的结点
        1. 如果一个字符对应的结点在字典树中不存在，则当前的搜索结果失败，回到上一个单词的结尾继续搜索
        2. 如果一个字符对应的结点是单词的结尾，则找到了一个更短的单词，从该字符的后一个字符开始搜索下一个更短的单词

方法二: 动态规划 + 字符串哈希
判断单词是不是连接词:
    dp[i]表示 word[:i] 能够切分出的最大 item 数的个数
    从 dp[i] 出发，枚举范围 [i + 1, n]，找到可由 dp[i] 所能更新的状态 dp[j]，并尝试使用 dp[i] 来更新 dp[j]
    状态转移方程: dp[j] = max(dp[j], dp[i] + 1)

通过「字符串哈希」方式来优化判断某个子串是否存在于 words 中
预处理每个 words[i] 的哈希值，并存入 HashSet 中, 之后判断某个数是否存在于 HashSet 中
'''

from collections import defaultdict, deque, Counter
from typing import List
import re
import math
import heapq
import collections
import bisect
import random


class Trie:
    def __init__(self):
        self.children = [None] * 26
        self.is_end = False

    def insert(self, word):
        node = self
        for c in word:
            idx = ord(c) - ord('a')
            if not node.children[idx]:
                node.children[idx] = Trie()
            node = node.children[idx]
        node.is_end = True

    def search(self, word, start):
        if start == len(word):
            return True
        node = self
        for i in range(start, len(word)):
            node = node.children[ord(word[i]) - ord('a')]
            # 如果某个字符对应的结点不存在
            if not node:
                return False
            # 如果找到了结尾符，从该字符的后一个字符开始搜索下一个更短的单词
            if node.is_end and self.search(word, i + 1):
                return True
        return False


class Solution:
    # 方法一：字典树
    def findAllConcatenatedWordsInADict(self, words: List[str]) -> List[str]:
        words.sort(key=len)
        ans = []
        trie = Trie()
        for word in words:
            if not word:
                continue
            # 从 word 的第一个字符开始，在字典树中依次搜索每个字符对应的结点
            if trie.search(word, 0):
                ans.append(word)
            else:
                trie.insert(word)
        return ans

    # 方法二：动态规划 + 字符串哈希
    # def findAllConcatenatedWordsInADict(self, words: List[str]) -> List[str]:
    #     def check(word: str):
    #         n = len(word)
    #         # dp[i]表示 word[:i] 能够切分出的最大 item 数的个数
    #         dp = [-1] * (n + 1)
    #         dp[0] = 0
    #         # 枚举每个子串
    #         for i in range(n + 1):
    #             if dp[i] == -1:
    #                 continue
    #             cur = 0
    #             # 遍历以 word[i] 开头的每个子串
    #             # 若子串在列表中，则更新 dp[j] = max(dp[j], dp[i] + 1)
    #             for j in range(i + 1, n + 1):
    #                 cur = cur * B + ord(word[j - 1]) - ord('a') + OFFSET
    #                 # 若哈希值相同，则说明
    #                 if cur in st:
    #                     dp[j] = max(dp[j], dp[i] + 1)
    #                 if dp[n] > 1:
    #                     return True
    #         return False

    #     # 字符串哈希冲突通过增加 offset 解决
    #     B, OFFSET = 131, 128
    #     st = set()
    #     # 字符串哈希判断某个子串是否存在于 wordswords 中
    #     for w in words:
    #         h = 0
    #         for c in w:
    #             h = h * B + ord(c) - ord('a') + OFFSET
    #         st.add(h)
    #     ans = []
    #     for w in words:
    #         if check(w):
    #             ans.append(w)
    #     return ans
