'''
Descroption: ������ 10.01. �ϲ����������
Author: EmoryHuang
Date: 2021-07-18 15:02:29
����˼·:
һ���򵥵ķ������ǽ����� B �Ž����� A ��β����Ȼ��ֱ������
�ٽ�һ���Ļ�����ʹ��˫ָ�룬�������ұȽ�������Ԫ�صĴ�С����Ԫ�طŵ��µ�������
��Ȼ������ A �������㹻�Ŀռ䣬��˿���ʹ������˫ָ��
'''


class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        i, j = m - 1, n - 1
        tail = m + n - 1
        while i >= 0 or j >= 0:
            if i == -1:
                A[tail] = B[j]
                j -= 1
            elif j == -1:
                A[tail] = A[i]
                i -= 1
            elif A[i] > B[j]:
                A[tail] = A[i]
                i -= 1
            else:
                A[tail] = B[j]
                j -= 1
            tail -= 1
