'''
Descroption: LeetCode 1936. ����������̨����
Author: EmoryHuang
Date: 2021-07-21 21:07:13
����˼·:
̰��
ά����ǰλ�� pos 
����ܵ������̨��, ��������̨��
������ܵ������̨�ף����̨�׵��ܵ���Ϊֹ
'''


class Solution:
    def addRungs(self, rungs: List[int], dist: int) -> int:
        pos, cnt = 0, 0
        for rung in rungs:
            # ������ܵ������̨��
            if pos + dist < rung:
                # ̰�����̨��
                cnt += (rung - pos - 1) // dist
            pos = rung  # �������̨��
        return cnt
