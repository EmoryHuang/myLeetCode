'''
Descroption: LeetCode 1232. ׺�����
Author: EmoryHuang
Date: 2021-06-21 21:15:00
����˼·:
���⣬�ж�ÿ������֮���б���Ƿ���ȣ�
ע�⽫����ת��Ϊ�˷���б�ʿ���Ϊ���
'''


class Solution:
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        x0, y0 = coordinates[0][0], coordinates[0][1]
        x = coordinates[1][0] - x0
        y = coordinates[1][1] - y0
        for p in coordinates:
            xi, yi = p[0] - x0, p[1] - y0
            if x * yi - y * xi:
                return False
        return True
