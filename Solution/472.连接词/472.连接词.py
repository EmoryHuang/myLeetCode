'''
Descroption: LeetCode 472. ���Ӵ�
Author: EmoryHuang
Date: 2021-12-28 12:09:18
Method:
����һ: �ֵ���
����ÿ���ǿյ��ʣ��жϸõ����ǲ������Ӵʣ�
��������Ӵ��򽫸õ��ʼ��������飬����������Ӵ��򽫸õ��ʼ����ֵ���

�жϵ����ǲ������Ӵ�: 
    �ӵ��ʵĵ�һ���ַ���ʼ�����ֵ�������������ÿ���ַ���Ӧ�Ľ��
        1. ���һ���ַ���Ӧ�Ľ�����ֵ����в����ڣ���ǰ���������ʧ�ܣ��ص���һ�����ʵĽ�β��������
        2. ���һ���ַ���Ӧ�Ľ���ǵ��ʵĽ�β�����ҵ���һ�����̵ĵ��ʣ��Ӹ��ַ��ĺ�һ���ַ���ʼ������һ�����̵ĵ���

������: ��̬�滮 + �ַ�����ϣ
�жϵ����ǲ������Ӵ�:
    dp[i]��ʾ word[:i] �ܹ��зֳ������ item ���ĸ���
    �� dp[i] ������ö�ٷ�Χ [i + 1, n]���ҵ����� dp[i] ���ܸ��µ�״̬ dp[j]��������ʹ�� dp[i] ������ dp[j]
    ״̬ת�Ʒ���: dp[j] = max(dp[j], dp[i] + 1)

ͨ�����ַ�����ϣ����ʽ���Ż��ж�ĳ���Ӵ��Ƿ������ words ��
Ԥ����ÿ�� words[i] �Ĺ�ϣֵ�������� HashSet ��, ֮���ж�ĳ�����Ƿ������ HashSet ��
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
            # ���ĳ���ַ���Ӧ�Ľ�㲻����
            if not node:
                return False
            # ����ҵ��˽�β�����Ӹ��ַ��ĺ�һ���ַ���ʼ������һ�����̵ĵ���
            if node.is_end and self.search(word, i + 1):
                return True
        return False


class Solution:
    # ����һ���ֵ���
    def findAllConcatenatedWordsInADict(self, words: List[str]) -> List[str]:
        words.sort(key=len)
        ans = []
        trie = Trie()
        for word in words:
            if not word:
                continue
            # �� word �ĵ�һ���ַ���ʼ�����ֵ�������������ÿ���ַ���Ӧ�Ľ��
            if trie.search(word, 0):
                ans.append(word)
            else:
                trie.insert(word)
        return ans

    # ����������̬�滮 + �ַ�����ϣ
    # def findAllConcatenatedWordsInADict(self, words: List[str]) -> List[str]:
    #     def check(word: str):
    #         n = len(word)
    #         # dp[i]��ʾ word[:i] �ܹ��зֳ������ item ���ĸ���
    #         dp = [-1] * (n + 1)
    #         dp[0] = 0
    #         # ö��ÿ���Ӵ�
    #         for i in range(n + 1):
    #             if dp[i] == -1:
    #                 continue
    #             cur = 0
    #             # ������ word[i] ��ͷ��ÿ���Ӵ�
    #             # ���Ӵ����б��У������ dp[j] = max(dp[j], dp[i] + 1)
    #             for j in range(i + 1, n + 1):
    #                 cur = cur * B + ord(word[j - 1]) - ord('a') + OFFSET
    #                 # ����ϣֵ��ͬ����˵��
    #                 if cur in st:
    #                     dp[j] = max(dp[j], dp[i] + 1)
    #                 if dp[n] > 1:
    #                     return True
    #         return False

    #     # �ַ�����ϣ��ͻͨ������ offset ���
    #     B, OFFSET = 131, 128
    #     st = set()
    #     # �ַ�����ϣ�ж�ĳ���Ӵ��Ƿ������ wordswords ��
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
