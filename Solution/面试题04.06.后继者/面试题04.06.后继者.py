'''
Descroption: 面试题 04.06. 后继者
Author: EmoryHuang
Date: 2022-05-16 08:54:40
Method:
利用二叉搜索树的性质，判断根节点与目标节点值的大小
'''


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def inorderSuccessor(self, root: TreeNode, p: TreeNode) -> TreeNode:
        if not root:
            return None
        if root.val <= p.val:
            return self.inorderSuccessor(root.right, p)
        else:
            left = self.inorderSuccessor(root.left, p)
            return left if left else root
