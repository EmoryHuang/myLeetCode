'''
Descroption: LeetCode 836. �����ص�
Author: EmoryHuang
Date: 2021-06-19 14:14:00
����˼·:
���⣬�ų����ཻ���������
����Ҫ�жϣ��ǲ���һ������
'''


class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        # �ж��ǲ��Ǿ���
        if rec1[0] == rec1[2] or rec1[1] == rec1[3] or rec2[0] == rec2[2] or rec2[1] == rec2[3]:
            return False
        # �ж�λ��
        if rec2[1] >= rec1[3] or rec1[1] >= rec2[3]:
            return False
        if rec1[0] >= rec2[2] or rec1[2] <= rec2[0]:
            return False
        return True
