'''
Descroption: ��ָ Offer 27. �������ľ���
Author: EmoryHuang
Date: 2021-07-02 15:03:00
����˼·:
ʹ��һ����ʱ�ڵ㱣�棬Ȼ��ݹ�ؽ�����������
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
