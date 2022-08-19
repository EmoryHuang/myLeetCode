'''
Descroption: LeetCode 684. ��������
Author: EmoryHuang
Date: 2021-08-01 14:28:33
Method:
���鼯
����������㲻λ��ͬһ����ͨ�����У���ô�ϲ����������㲻�ᵼ�»��ĳ���
���λ��ͬһ����ͨ�����У���ô�ϲ�����������ᵼ�»��ĳ���
'''


class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        def find(x: int) -> int:
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]

        def union(x: int, y: int):
            parent[find(x)] = find(y)

        n = len(edges)
        parent = list(range(n + 1))
        for x, y in edges:
            # �����λ��ͬһ����ͨ������
            # ��ô�ϲ����������㲻�ᵼ�»��ĳ���
            if find(x) != find(y):
                union(x, y)
            # ���λ��ͬһ����ͨ������
            # ��ô�ϲ�����������ᵼ�»��ĳ���
            else:
                return [x, y]
