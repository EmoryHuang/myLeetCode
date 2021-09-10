'''
Descroption: LeetCode 1598. �ļ��в�����־�Ѽ���
Author: EmoryHuang
Date: 2021-06-20 12:41:00
����˼·:
�� log == './' �����в���
�� log == '../ �� cnt - 1
���� cnt + 1
'''


class Solution:
    def minOperations(self, logs: List[str]) -> int:
        cnt = 0
        for log in logs:
            if log == './':
                pass
            elif log == '../':
                cnt = max(0, cnt - 1)
            else:
                cnt += 1
        return cnt
