'''
Descroption: LeetCode 869. ��������õ� 2 ����
Author: EmoryHuang
Date: 2021-10-28 08:59:50
Method:
���ö�ٳ� 1e9 ������ 2 ����
ͳ�� n �и������ֵĸ���
Ȼ��������� 2 �������Ƿ����һ���������������ֵĸ����� n ��ͬ
'''


class Solution:
    def reorderedPowerOf2(self, n: int) -> bool:
        # ��� 2 ����
        power = [Counter(str(1 << i)) for i in range(30)]
        # ͳ�� n �и������ֵĸ���
        cnt = Counter(str(n))
        return any(cnt == s for s in power)