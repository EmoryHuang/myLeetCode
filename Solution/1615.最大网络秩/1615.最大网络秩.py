'''
Descroption: LeetCode 1615. ���������
Author: EmoryHuang
Date: 2021-08-10 20:32:27
Method:
��ͼ��ͳ��ÿ���ڵ�Ķ�
�����ڵ�ԣ�Ѱ�Ҷ�֮�����Ľڵ��
���������ڵ��֮����·�������1
'''


class Solution:
    def maximalNetworkRank(self, n: int, roads: List[List[int]]) -> int:
        graph = defaultdict(list)
        degree = [0] * n
        for u, v in roads:
            graph[u].append(v)
            graph[v].append(u)
            # ͳ�ƽڵ�ĳ����
            degree[u] += 1
            degree[v] += 1
        ans, sum = 0, 0
        for i in range(1, n):
            for j in range(i):
                sum = degree[i] + degree[j]
                # ����ڵ��֮����·��
                if i in graph[j]:
                    sum -= 1
                ans = max(ans, sum)
        return ans