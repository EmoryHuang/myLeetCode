'''
Descroption: LeetCode 1832. 判断句子是否为全字母句
Author: EmoryHuang
Date: 2022-12-13 09:13:44
Method:
简单题，计数字母出现种类
'''

class Solution:
    def checkIfPangram(self, sentence: str) -> bool:
        return len(Counter(sentence)) == 26