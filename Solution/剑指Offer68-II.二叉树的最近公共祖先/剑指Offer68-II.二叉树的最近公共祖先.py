'''
Descroption: LeetCode 236. 二叉树的最近公共祖先
Author: EmoryHuang
Date: 2021-06-04 13:27:00
解题思路:
遍历左分支右分支
当left和right都不为空的时候说明他们分别在某一个root的左右分支中
'''


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if root == None or p == root or q == root:
            return root
        left = self.lowestCommonAncestor(root.left, p, q)
        right = self.lowestCommonAncestor(root.right, p, q)
        if left and right:
            return root
        elif left == None:
            return right
        else:
            return left
