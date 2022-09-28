'''
Descroption: LeetCode 953. 验证外星语词典
Author: EmoryHuang
Date: 2022-05-17 08:48:40
Method:
按 order 的规则比较
'''


class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        hashmap = {c: i for i, c in enumerate(order)}
        return words == sorted(words, key=lambda w: [hashmap[x] for x in w])