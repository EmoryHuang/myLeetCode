'''
Descroption: 
Author: EmoryHuang
Date: 2021-07-28 12:30:50
Method: 
'''
'''
Descroption: LeetCode 863. 二叉树中所有距离为 K 的结点
Author: EmoryHuang
Date: 2021-07-28 13:35:33
Method:
由于每个节点的值都不相同，因此我们可以使用哈希表记录每个节点的父节点
然后从目标节点出发，进行深度优先遍历，从三个方向上进行搜索
找到深度为k的节点
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> List[int]:
        parents = defaultdict(list)
        ans = []

        def find_parent(root: TreeNode) -> None:
            if root.left:
                parents[root.left.val] = root
                find_parent(root.left)
            if root.right:
                parents[root.right.val] = root
                find_parent(root.right)

        def find_deep_k(node: TreeNode, parent: TreeNode, depth: int) -> None:
            if not node:
                return
            if depth == k:
                ans.append(node.val)
                return
            if node.left != parent:
                find_deep_k(node.left, node, depth + 1)
            if node.right != parent:
                find_deep_k(node.right, node, depth + 1)
            if parents[node.val] != parent:
                find_deep_k(parents[node.val], node, depth + 1)

        find_parent(root)
        find_deep_k(target, None, 0)
        return ans
