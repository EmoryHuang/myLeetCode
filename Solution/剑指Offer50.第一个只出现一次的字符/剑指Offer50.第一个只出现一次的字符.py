'''
Descroption: ��ָ Offer 50. ��һ��ֻ����һ�ε��ַ�
Author: EmoryHuang
Date: 2021-07-29 19:24:06
Method:
���⣬ʹ�ù�ϣ�����
'''


class Solution:
    def firstUniqChar(self, s: str) -> str:
        hash = defaultdict(int)
        for c in s:
            hash[c] += 1
        for c in s:
            if hash[c] == 1:
                return c
        return ' '