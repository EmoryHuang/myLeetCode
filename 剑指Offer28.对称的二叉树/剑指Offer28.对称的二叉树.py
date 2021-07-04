'''
Descroption: ��ָ Offer 28. �ԳƵĶ�����
Author: EmoryHuang
Date: 2021-07-04 13:30:48
����˼·:
�ݹ�رȽ������ڵ��Ƿ���ͬ
'''


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if not root:
            return True

        def cmp(root1: TreeNode, root2: TreeNode) -> bool:
            if not root1 and not root2:
                return True
            if not root1 or not root2:
                return False
            if root1.val != root2.val:
                return False
            return cmp(root1.left, root2.right) and cmp(root1.right, root2.left)

        return cmp(root.left, root.right)
