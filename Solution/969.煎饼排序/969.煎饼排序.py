'''
Descroption: LeetCode 969. �������
Author: EmoryHuang
Date: 2022-02-19 09:05:53
Method:
���� arr �� 1 �� n �����У���˿���ÿ������ȷ��һ�����ֵ
�Ӻ���ǰö��ÿ��λ����Ҫ��Ԫ��
�ҵ���ǰ��Ҫ��Ԫ���� arr �е�λ�� idx
����Ҫ��Ԫ�ز��ڵ�һ��λ�ã����ȷ�ת [0, idx]���������Ա�֤��һ��λ������Ҫ��Ԫ��
����Ҫ��Ԫ���ڵ�һ��λ�ã���ֱ�ӷ�ת [0, i - 1]
'''


class Solution:
    def pancakeSort(self, arr: List[int]) -> List[int]:
        n = len(arr)
        ans = []
        # �Ӻ���ǰö��ÿ��λ����Ҫ��Ԫ��
        for i in range(n, 1, -1):
            # �ҵ���ǰ��Ҫ��Ԫ�ص�λ��
            idx = arr.index(i)
            # ��λ�ò���Ҫ�ı�
            if idx == i - 1:
                continue
            if idx != 0:
                # ����Ҫ��Ԫ�ز��ڵ�һ��λ�ã����ȷ�ת [0, idx]���������Ա�֤��һ��λ������Ҫ��Ԫ��
                ans.append(idx + 1)
                arr = arr[idx::-1] + arr[idx + 1:]
            # ����Ҫ��Ԫ���ڵ�һ��λ�ã���ֱ�ӷ�ת [0, i - 1]
            ans.append(i)
            arr = arr[i - 1::-1] + arr[i:]
        return ans