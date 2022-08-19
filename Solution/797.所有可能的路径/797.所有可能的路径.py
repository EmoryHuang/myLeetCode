'''
Descroption: LeetCode 797. ���п��ܵ�·��
Author: EmoryHuang
Date: 2021-08-25 15:24:16
Method:
��Ϊ�������޻�ͼ������������Ѿ��߹��Ľڵ㣬����һֱ��ȱ������ɡ�
������һ���ڵ���Ŀ��ڵ��Ǿ�ֱ�Ӽ��뵽 ans ��
'''


class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        def dfs(node: int) -> None:
            if node == len(graph) - 1:
                ans.append(path[:])
            for ne in graph[node]:
                path.append(ne)
                dfs(ne)
                path.pop()

        ans, path = [], [0]
        dfs(0)
        return ans