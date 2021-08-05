'''
Descroption: LeetCode 1791. �ҳ�����ͼ�����Ľڵ�
Author: EmoryHuang
Date: 2021-08-05 20:17:30
Method:
���⣬�����ڽӱ�Ѱ�����ڽڵ���Ϊ n - 1 �Ľڵ�
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
