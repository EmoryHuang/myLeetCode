'''
Descroption: LeetCode 1812. �жϹ�������������һ�����ӵ���ɫ
Author: EmoryHuang
Date: 2021-06-17 15:49:00
����˼·:
���⣬������������Ϊ���������ǰ�ɫ������Ϊ��
'''


class Solution:
    def squareIsWhite(self, coordinates: str) -> bool:
        ind = ord(coordinates[0]) + int(coordinates[1])
        return ind % 2 == 1
