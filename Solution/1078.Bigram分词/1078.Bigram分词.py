'''
Descroption: LeetCode 1078. Bigram �ִ�
Author: EmoryHuang
Date: 2021-12-26 09:48:16
Method:
���⣬�����ַ������Ƚ��������������Ƿ���ͬ
�����������ʼ��� ans
'''


class Solution:
    def findOcurrences(self, text: str, first: str, second: str) -> List[str]:
        text = text.split()
        res = []
        for i in range(2, len(text)):
            if text[i - 2] == first and text[i - 1] == second:
                res.append(text[i])
        return res