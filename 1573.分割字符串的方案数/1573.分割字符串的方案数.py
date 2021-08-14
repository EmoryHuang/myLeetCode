'''
Descroption: LeetCode 1573. �ָ��ַ����ķ�����
Author: EmoryHuang
Date: 2021-08-14 14:39:49
Method:
�������
�����ַ�����1��λ�ú�����
�� 1 ������Ϊ 0��˵��û�� 1����ô���ΪC(2,n-1)���� (n - 1) * (n - 2) / 2
���򣬿���ÿ��������֮�����һ�� 1 �͵�һ�� 1 �ľ���
Ȼ������������ԭ�����
'''


class Solution:
    def numWays(self, s: str) -> int:
        ones = []
        n = len(s)
        for i, c in enumerate(s):
            if c == '1':
                ones.append(i)
        cnt = len(ones)
        if cnt % 3 != 0:
            return 0
        if cnt == 0:
            return (n - 1) * (n - 2) // 2 % 1000000007
        else:
            ind1, ind2 = cnt // 3, cnt // 3 * 2
            # ��һ�������һ�� 1 �͵ڶ����ֵ�һ�� 1 �ľ���
            cnt1 = ones[ind1] - ones[ind1 - 1]
            # �ڶ��������һ�� 1 �͵������ֵ�һ�� 1 �ľ���
            cnt2 = ones[ind2] - ones[ind2 - 1]
            return cnt1 * cnt2 % 1000000007