'''
Descroption: LeetCode 670. ��󽻻�
Author: EmoryHuang
Date: 2021-11-08 20:57:40
Method:
����һ������
Ѱ�ҵ�ǰ�ַ���������ֵ�������ֵ��Ϊ��ǰ�ַ�������н���

������������
�� num �е����ִӴ�С�Ľ�������
Ȼ����ԭ����һһ�Ƚϣ������ĵ�һ����ͬ��ֵ������Ҫ������ֵ
'''


class Solution:
    def maximumSwap(self, num: int) -> int:
        a = list(str(num))
        b = sorted(a, reverse=True)
        idx = -1
        for i in range(len(a)):
            if a[i] != b[i]:
                idx = i
                break
        if idx == -1:
            return num
        for i in range(len(a) - 1, -1, -1):
            if a[i] == b[idx]:
                a[i], a[idx] = a[idx], a[i]
        return int(''.join(a))
