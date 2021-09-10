'''
Descroption: LeetCode 543. 二叉树的直径
Author: EmoryHuang
Date: 2021-07-30 15:46:13
Method:
深度优先搜索
转换一下题目的意思也就是求二叉树左右子树的深度
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        self.ans = 1

        def depth(node: TreeNode) -> int:
            if not node:
                return 0
            l = depth(node.left)
            r = depth(node.right)
            self.ans = max(self.ans, l + r + 1)
            return max(l, r) + 1

        depth(root)
        return self.ans - 1
