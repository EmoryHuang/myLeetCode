'''
Descroption: LeetCode 1436. �����յ�վ
Author: EmoryHuang
Date: 2021-06-05 15:44:00
����˼·:
����㼯����Ѱ���յ㣬û�г�������㼯���еļ����յ�վ
'''


class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        start = [i[0] for i in paths]
        for j in paths:
            if j[1] not in start:
                return j[1]
