'''
Descroption: 面试题 16.02. 单词频率
Author: EmoryHuang
Date: 2021-07-18 14:33:15
解题思路:
哈希表
'''


class WordsFrequency:

    def __init__(self, book: List[str]):
        self.mp = defaultdict(int)
        for s in book:
            self.mp[s] += 1

    def get(self, word: str) -> int:
        return self.mp[word]

# Your WordsFrequency object will be instantiated and called as such:
# obj = WordsFrequency(book)
# param_1 = obj.get(word)
