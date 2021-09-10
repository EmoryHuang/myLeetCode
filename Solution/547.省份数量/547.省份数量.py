'''
Descroption: LeetCode 547. ʡ������
Author: EmoryHuang
Date: 2021-08-01 13:44:25
Method:
�������⣬����ͨ������
����һ�����鼯
�����������������ͬ����ͨ��������ϲ�
��������dfs
�������г��У�����ÿ�����У�����ó�����δ�����ʹ�����Ӹó��п�ʼ�����������
������ȫ�������Ժ󣬼��ɵõ���ͨ����������
'''


class Solution:
    # ����һ�����鼯
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        def find(x: int) -> int:
            if x != parent[x]:
                parent[x] = find(parent[x])
            return parent[x]

        def union(x: int, y: int) -> None:
            parent[find(x)] = find(y)

        n = len(isConnected)  # ���е�����
        parent = list(range(n))  # ��ʼ�����鼯
        for i in range(n):
            for j in range(i + 1, n):
                if isConnected[i][j] == 1:
                    union(i, j)
        ans = 0
        for i, p in enumerate(parent):
            if p == i:
                ans += 1
        return ans

    # ��������dfs
    # def findCircleNum(self, isConnected: List[List[int]]) -> int:
    #     def dfs(i: int):
    #         for j in range(n):
    #             if isConnected[i][j] == 1 and j not in vis:
    #                 vis.add(j)
    #                 dfs(j)

    #     n = len(isConnected)
    #     vis = set()
    #     ans = 0
    #     for i in range(n):
    #         if i not in vis:
    #             dfs(i)
    #             ans += 1
    #     return ans
