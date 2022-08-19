'''
Descroption: LeetCode 1719. 重构一棵树的方案数
Author: EmoryHuang
Date: 2022-02-16 09:49:17
Method:
adj[x] 存储节点 x 的所有祖先和后代
首先寻找根节点，根节点的所有祖先和后代的数目为 n - 1
遍历每个节点 node，找到当前节点的父节点 parent
若 parent 为父节点，则必有父节点的祖孙关系数目 ≥ 子孙节点的祖孙关系数目
parent 的祖先和后代中必定包含了 node 的祖先和后代（除 parent 本身）
若不能完全包含则说明不成立
若 parent 和 node 的祖先和后代数目相同，则无法确定父子关系，可能存在多种构造
'''


class Solution:
    def checkWays(self, pairs: List[List[int]]) -> int:
        # adj[x] 存储节点 x 的所有祖先和后代
        adj = defaultdict(set)
        for i, j in pairs:
            adj[i].add(j)
            adj[j].add(i)
        root = -1
        for node, neighb in adj.items():
            # 寻找根节点，根节点的所有祖先和后代的数目为 n - 1
            if len(neighb) == len(adj) - 1:
                root = node
                break
        # 根节点不存在，则返回 0
        if root == -1:
            return 0
        ans = 1
        for node, neighb in adj.items():
            if node == root:
                continue
            # 在当前节点 node 的祖先和后代中寻找当前节点的父节点
            # 若 parent 为父节点，则必有父节点的祖孙关系数目 ≥ 子孙节点的祖孙关系数目
            cur_degree = len(neighb)
            parent = -1
            parent_degree = float('inf')
            for n in neighb:
                if cur_degree <= len(adj[n]) < parent_degree:
                    parent = n
                    parent_degree = len(adj[n])
            if parent == -1:
                return 0
            # 确定 node 的其他祖先和后代关系是否成立
            # parent 的祖先和后代中必定包含了 node 的祖先和后代（除 parent 本身）
            for n in neighb:
                if n == parent:
                    continue
                # 若不能完全包含则说明不成立
                if n not in adj[parent]:
                    return 0
            # 无法确定父子关系，可能存在多种构造
            if cur_degree == parent_degree:
                ans = 2
        return ans