'''
Descroption: LeetCode 884. ���仰�еĲ���������
Author: EmoryHuang
Date: 2021-08-26 18:37:15
Method:
���⣬��ϣ�������Ѱ��ֻ����һ�εĵ���
'''


class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        s = s1.split(' ') + s2.split(' ')
        return [word for word in s if s.count(word) == 1]
