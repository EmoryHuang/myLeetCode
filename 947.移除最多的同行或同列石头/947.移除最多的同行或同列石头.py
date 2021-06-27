'''
Descroption: LeetCode 947. �Ƴ�����ͬ�л�ͬ��ʯͷ
Author: EmoryHuang
Date: 2021-06-27 14:50:00
����˼·:
���鼯
���������㣬��ͬһ�л���ͬһ����ϲ�
��������ͨͼ��������ô�����Ƴ���ʯ�ӵ��������Ϊ n - ��ͨͼ����
'''


class Solution:
    def removeStones(self, stones: List[List[int]]) -> int:
        n = len(stones)
        parent = list(range(n))  # ��ʼ�����鼯

        def find(x: int) -> int:
            if x != parent[x]:
                parent[x] = find(parent[x])
            return parent[x]

        def union(x: int, y: int) -> None:
            parent[find(x)] = find(y)

        for i in range(n):
            for j in range(i + 1, n):
                # ��ͬһ�л���ͬһ����ϲ�
                if stones[i][0] == stones[j][0] or stones[i][1] == stones[j][1]:
                    union(i, j)
        ans = 0
        for i in range(n):
            if parent[i] == i:  # ��ͨͼ����
                ans += 1
        return n - ans