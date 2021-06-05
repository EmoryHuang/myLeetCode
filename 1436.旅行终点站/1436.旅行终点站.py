'''
Descroption: LeetCode 1436. 旅行终点站
Author: EmoryHuang
Date: 2021-06-05 15:44:00
解题思路:
在起点集合中寻找终点，没有出现在起点集合中的即是终点站
'''


class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        start = [i[0] for i in paths]
        for j in paths:
            if j[1] not in start:
                return j[1]
