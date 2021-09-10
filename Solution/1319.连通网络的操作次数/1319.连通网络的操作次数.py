'''
Descroption: LeetCode 1319. ��ͨ����Ĳ�������
Author: EmoryHuang
Date: 2021-08-01 14:05:13
Method:
���鼯����ͨ������
ÿ�ɹ�����һ�κϲ���������ͨ�������ͻ���� 1
'''


class Solution:
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        def find(x: int) -> int:
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]

        def union(x: int, y: int):
            parent[find(x)] = find(y)

        edges = len(connections)
        # n ������������Ҫ n - 1 ����
        if edges < n - 1:
            return -1
        parent = list(range(n))
        for x, y in connections:
            union(x, y)
        ans = 0
        for i in range(n):
            if parent[i] == i:
                ans += 1
        return ans - 1