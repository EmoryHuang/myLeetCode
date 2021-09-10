'''
Descroption: LeetCode 1791. 找出星型图的中心节点
Author: EmoryHuang
Date: 2021-08-05 20:17:30
Method:
简单题，构建邻接表，寻找相邻节点数为 n - 1 的节点
'''


class Solution:
    def findCenter(self, edges: List[List[int]]) -> int:
        mp = defaultdict(list)
        for u, v in edges:
            mp[u].append(v)
            mp[v].append(u)
        for key, val in mp.items():
            if len(val) == len(edges):
                return key
