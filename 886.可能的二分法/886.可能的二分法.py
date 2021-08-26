'''
Descroption: LeetCode 886. 可能的二分法
Author: EmoryHuang
Date: 2021-08-26 16:55:05
Method:
方法一：并查集
对于每个人，遍历所有他们不喜欢的人，若不喜欢的两个人在同一组，则不满足
同时，被同一个人不喜欢的必须在同一组，否则不会是二分图

方法二：染色法
对于每个连通的部分，用两种颜色对它进行着色，就可以检查它是否是二分的。
将任一结点涂成白色，然后将它的所有邻居都涂成黑色，
然后将所有的邻居的邻居都涂成白色，以此类推。
若产生冲突则说明不是二分图。
'''


class Solution:
    # 方法一：并查集
    # def possibleBipartition(self, n: int, dislikes: List[List[int]]) -> bool:
    #     def find(x: int) -> int:
    #         if x != parent[x]:
    #             parent[x] = find(parent[x])
    #         return parent[x]

    #     def merge(x: int, y: int) -> None:
    #         parent[find(x)] = find(y)

    #     # 初始化并查集
    #     parent = list(range(n + 1))
    #     # 建立邻接表
    #     mp = defaultdict(list)
    #     for a, b in dislikes:
    #         mp[a].append(b)
    #         mp[b].append(a)
    #     for i in range(1, n + 1):
    #         for j in mp[i]:
    #             # 若不喜欢的两个人在同一组，则不满足
    #             if find(i) == find(j):
    #                 return False
    #             # 被同一个人不喜欢的必须在同一组，否则不会是二分图
    #             merge(mp[i][0], j)
    #     return True

    # 方法二：染色法
    def possibleBipartition(self, n: int, dislikes: List[List[int]]) -> bool:
        def dfs(u: int, c: int) -> bool:
            # u表示当前节点，c表示当前点的颜色
            color[u] = c
            # 遍历 u 的邻接节点
            for v in mp[u]:
                # 如果当前节点未染色
                if not color[v]:
                    # 将相邻的点染成相反的颜色
                    if not dfs(v, -c): return False
                elif color[v] == c:
                    # 结点v已经着色，且和结点u颜色冲突
                    return False
            return True

        mp = defaultdict(list)
        for a, b in dislikes:
            mp[a].append(b)
            mp[b].append(a)
        # 0表示未染色，1表示黑色，-1表示白色
        color = [0] * (n + 1)
        flag = True
        for i in range(1, n + 1):
            # 如果当前节点未染色
            if not color[i]:
                if not dfs(i, 1):
                    flag = False
                    break
        return flag
