'''
Descroption: LeetCode 937. ����������־�ļ�
Author: EmoryHuang
Date: 2022-05-03 10:40:10
Method:
������
'''

class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        def trans(log: str) -> tuple:
            a, b = log.split(' ', 1)
            return (0, b, a) if b[0].isalpha() else (1,)

        logs.sort(key=trans)  # sort ���ȶ�����
        return logs
