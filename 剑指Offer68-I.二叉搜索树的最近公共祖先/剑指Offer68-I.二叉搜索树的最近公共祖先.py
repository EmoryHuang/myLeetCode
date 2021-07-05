'''
Descroption: 剑指 Offer 68 - I. 二叉搜索树的最近公共祖先
Author: EmoryHuang
Date: 2021-07-04 15:20:48
解题思路:
根据二叉搜索树的性质递归遍历
'''


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if not root:
            return
        # p, q 都在左子树
        if root.val > q.val and root.val > p.val:
            return self.lowestCommonAncestor(root.left, p, q)
        # p, q 都在右子树
        if root.val < q.val and root.val < p.val:
            return self.lowestCommonAncestor(root.right, p, q)
        return root
