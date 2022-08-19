'''
Descroption: LeetCode 819. 最常见的单词
Author: EmoryHuang
Date: 2021-07-28 17:20:25
Method:
简单题，哈希表计数
'''


class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        paragraph = paragraph.lower()
        paragraph = paragraph.replace(',', ' ')
        paragraph = paragraph.replace('.', ' ')
        paragraph = paragraph.replace('!', ' ')
        paragraph = paragraph.replace('?', ' ')
        paragraph = paragraph.replace(';', ' ')
        paragraph = paragraph.replace('\'', ' ')
        l = paragraph.split()
        dic = collections.Counter(l)
        m = 0
        for word in dic:
            if word not in banned:
                if m < dic[word]:
                    m = dic[word]
                    w = word
        return w
