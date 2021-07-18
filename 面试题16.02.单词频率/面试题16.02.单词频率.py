'''
Descroption: ������ 16.02. ����Ƶ��
Author: EmoryHuang
Date: 2021-07-18 14:33:15
����˼·:
��ϣ��
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
