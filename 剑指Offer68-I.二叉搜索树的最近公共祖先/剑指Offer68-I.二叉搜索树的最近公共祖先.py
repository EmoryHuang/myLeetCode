'''
Descroption: ��ָ Offer 68 - I. �����������������������
Author: EmoryHuang
Date: 2021-07-04 15:20:48
����˼·:
���ݶ��������������ʵݹ����
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
        # p, q ����������
        if root.val > q.val and root.val > p.val:
            return self.lowestCommonAncestor(root.left, p, q)
        # p, q ����������
        if root.val < q.val and root.val < p.val:
            return self.lowestCommonAncestor(root.right, p, q)
        return root
