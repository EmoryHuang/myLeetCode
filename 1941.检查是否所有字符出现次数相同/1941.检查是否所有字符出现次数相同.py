'''
Descroption: LeetCode 1941. ����Ƿ������ַ����ִ�����ͬ
Author: EmoryHuang
Date: 2021-07-29 19:41:33
Method:
���⣬ʹ�ù�ϣ�����
'''


class Solution:
    def areOccurrencesEqual(self, s: str) -> bool:
        return len(set(Counter(s).values())) == 1