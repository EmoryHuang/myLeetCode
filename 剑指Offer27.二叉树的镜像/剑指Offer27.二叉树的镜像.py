'''
Descroption: 剑指 Offer 27. 二叉树的镜像
Author: EmoryHuang
Date: 2021-07-02 15:03:00
解题思路:
使用一个临时节点保存，然后递归地交换左右子树
'''


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def mirrorTree(self, root: TreeNode) -> TreeNode:
        if not root:
            return None
        tmp = root.left
        root.left = self.mirrorTree(root.right)
        root.right = self.mirrorTree(tmp)
        return root
