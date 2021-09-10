'''
Descroption: ½£Ö¸ Offer II 034. ÍâÐÇÓïÑÔÊÇ·ñÅÅÐò
Author: EmoryHuang
Date: 2021-08-13 20:22:59
Method:
°´¸ø³öµÄ×ÖµäÐòÅÅÐò
'''


class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        return words == sorted(words, key=lambda x: [order.index(x) for x in x])
