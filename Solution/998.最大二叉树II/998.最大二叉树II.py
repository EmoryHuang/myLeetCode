'''
Descroption: LeetCode 998. 最大二叉树 II
Author: EmoryHuang
Date: 2022-08-30 09:10:02
Method:
遍历右子节点
若插入值 val 大于根节点，则将根节点作为其左孩子
否则，将其插入根节点的右孩子进行遍历
'''


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def insertIntoMaxTree(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        if root is None:
            return TreeNode(val)
        if root.val < val:
            node = TreeNode(val)
            node.left = root
            return node
        else:
            root.right = self.insertIntoMaxTree(root.right, val)
            return root
        return None