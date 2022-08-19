'''
Descroption: 剑指 Offer II 049. 从根节点到叶节点的路径数字之和
Author: EmoryHuang
Date: 2021-08-06 19:07:19
Method:
回溯法
枚举每一条从根节点到叶子节点的路径
若遍历到叶子节点，则将这条路径的和加入 ans
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def sumNumbers(self, root: TreeNode) -> int:
        self.ans = 0

        def dfs(node: TreeNode, cur: int):
            if not node:
                return
            if not node.left and not node.right:
                self.ans += cur * 10 + node.val
            dfs(node.left, cur * 10 + node.val)
            dfs(node.right, cur * 10 + node.val)

        dfs(root, 0)
        return self.ans