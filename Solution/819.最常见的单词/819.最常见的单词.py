'''
Descroption: LeetCode 819. ����ĵ���
Author: EmoryHuang
Date: 2021-07-28 17:20:25
Method:
���⣬��ϣ�����
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
