'''
Descroption: LeetCode 1104. ������Ѱ·
Author: EmoryHuang
Date: 2021-07-29 13:34:27
Method:
��ѧ
��Ϊż���У��򽫴���������ҵ������ת��
label = 2^(i - 1) + 2^(i) - 1 - label
'''


class Solution:
    def pathInZigZagTree(self, label: int) -> List[int]:
        ans = []
        row, start = 1, 1
        # row ��ʾ label ������
        # start ��ʾ label �����е���С����
        while start * 2 <= label:
            row += 1
            start *= 2
        # �� label ��ʾΪ�����ҵı��
        # 2^(i - 1) + 2^(i) - 1 - label
        if row % 2 == 0:
            label = (1 << row - 1) + (1 << row) - 1 - label
        while row:
            # ��Ϊż�������ʾΪ���ҵ���ı��
            if row % 2 == 0:
                ans.append((1 << row - 1) + (1 << row) - 1 - label)
            else:
                ans.append(label)
            row -= 1
            # ����Ϊ���ڵ�
            label >>= 1
        return ans[::-1]
