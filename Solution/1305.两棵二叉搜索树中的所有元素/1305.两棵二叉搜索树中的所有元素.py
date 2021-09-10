'''
Descroption: LeetCode 1305. 两棵二叉搜索树中的所有元素
Author: EmoryHuang
Date: 2021-07-19 19:26:15
解题思路:
排序 + 遍历
'''


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        ans = []

        def inorder(root: TreeNode):
            if not root:
                return
            inorder(root.left)
            ans.append(root.val)
            inorder(root.right)

        inorder(root1)
        inorder(root2)
        ans.sort()
        return ans
