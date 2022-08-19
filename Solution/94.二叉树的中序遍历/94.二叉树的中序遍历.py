'''
Descroption: LeetCode 94. 二叉树的中序遍历
Author: EmoryHuang
Date: 2021-06-07 21:06:00
解题思路:
方法一：递归
方法二：迭代
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    # 方法一：递归
    # def inorderTraversal(self, root: TreeNode) -> List[int]:
    #     ans = []
    #     def inorder(root: TreeNode):
    #         if root:
    #             inorder(root.left)
    #             ans.append(root.val)
    #             inorder(root.right)
    #     inorder(root)
    #     return ans

    # 方法二：迭代
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        stack = []
        ans = []
        while stack or root:
            while root:
                stack.append(root)
                root = root.left
            cur = stack.pop()
            ans.append(cur.val)
            root = cur.right
        return ans
