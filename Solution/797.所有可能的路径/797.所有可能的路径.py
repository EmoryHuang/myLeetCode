'''
Descroption: LeetCode 797. 所有可能的路径
Author: EmoryHuang
Date: 2021-08-25 15:24:16
Method:
因为是有向无环图，不会遍历到已经走过的节点，所以一直深度遍历即可。
如果最后一个节点是目标节点那就直接加入到 ans 中
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