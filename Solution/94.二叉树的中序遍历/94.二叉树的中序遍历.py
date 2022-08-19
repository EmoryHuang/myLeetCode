'''
Descroption: LeetCode 94. ���������������
Author: EmoryHuang
Date: 2021-06-07 21:06:00
����˼·:
����һ���ݹ�
������������
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    # ����һ���ݹ�
    # def inorderTraversal(self, root: TreeNode) -> List[int]:
    #     ans = []
    #     def inorder(root: TreeNode):
    #         if root:
    #             inorder(root.left)
    #             ans.append(root.val)
    #             inorder(root.right)
    #     inorder(root)
    #     return ans

    # ������������
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
