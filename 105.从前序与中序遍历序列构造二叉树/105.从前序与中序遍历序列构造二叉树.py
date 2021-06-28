'''
Descroption: LeetCode 105. ��ǰ��������������й��������
Author: EmoryHuang
Date: 2021-06-28 17:05:00
����˼·:
���������������������ؽ�������
���õݹ�ķ���
�������������ߵĽڵ��Ǹ��ڵ㣬
Ȼ���ٵ�����������ҵ����ڵ��λ�ã�������������һ��Ϊ��
'''


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if not preorder or not inorder:
            return None
        # ���ڵ�Ϊǰ��ĵ�һ��Ԫ��
        root = TreeNode(preorder[0])
        # ���������ҵ����ڵ��λ��
        mid = inorder.index(preorder[0])
        # ������������������
        root.left = self.buildTree(preorder[1:mid + 1], inorder[:mid])
        root.right = self.buildTree(preorder[mid + 1:], inorder[mid + 1:])
        return root
