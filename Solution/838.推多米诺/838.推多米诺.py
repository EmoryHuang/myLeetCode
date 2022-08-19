'''
Descroption: LeetCode 838. �ƶ���ŵ
Author: EmoryHuang
Date: 2022-02-21 09:01:19
Method:
˫ָ��
�ҵ�һ��������δ��ʩ���������䣬ͨ���������ߵķ�����ȷ��������ĵ���
left �� right ��ʾ���������������Ƶ��ķ���
������ͬ������һ�����򵹣�������ԣ����м䵹
'''


class Solution:
    def pushDominoes(self, dominoes: str) -> str:
        d = list(dominoes)
        # left �� right ��ʾ�Ƶ��ķ���
        n, i, left = len(dominoes), 0, 'L'
        while i < len(dominoes):
            j = i
            # �ҵ�һ��������δ��ʩ����������
            while j < n and dominoes[j] == '.':
                j += 1
            right = d[j] if j < n else 'R'
            if left == right:
                # ������ͬ����һ������
                while i < j:
                    d[i] = right
                    i += 1
            elif left == 'R' and right == 'L':
                # ������ԣ����м䵹
                k = j - 1
                while i < k:
                    d[i] = 'R'
                    d[k] = 'L'
                    i += 1
                    k -= 1
            left = right
            i = j + 1
        return ''.join(d)
