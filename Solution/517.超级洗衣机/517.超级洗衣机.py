'''
Descroption: LeetCode 517. ����ϴ�»�
Author: EmoryHuang
Date: 2021-09-29 09:25:42
Method:
̰��
�����ж��Ƿ��ܾ��֣��õ�Ŀ�� target
�� num - target < 0 ��ʾ��Ҫ�����߻�ȡ�·�, ������Ҫ�������ó��·�
p < 0 ˵����Ҫ���ұ߻�ȡ�·�, p > 0 ˵����Ҫ���ұ��ó��·�
���Ĳ����������� max(num - target, abs(p))
'''


class Solution:
    def findMinMoves(self, machines: List[int]) -> int:
        _sum, n = sum(machines), len(machines)
        if _sum % n != 0:
            return -1
        target = _sum // n
        ans, p = 0, 0
        for num in machines:
            # �� num - target < 0 ��ʾ��Ҫ�����߻�ȡ�·�
            # ������Ҫ�������ó��·�
            # p < 0 ˵����Ҫ���ұ߻�ȡ�·�
            # p > 0 ˵����Ҫ���ұ��ó��·�
            # ���Ĳ����������� max(num - target, abs(p))
            p += num - target
            ans = max(ans, num - target, abs(p))
        return ans
