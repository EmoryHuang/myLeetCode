'''
Descroption: ��ָ Offer II 053. �����������е�������
Author: EmoryHuang
Date: 2021-09-08 15:43:49
Method:
����һ���������
�����������¼�ڵ��ǰ������������ҵ�ָ���ڵ�����һ���ڵ�

������������������������
����ǰ�ڵ��ֵС�ڵ��ڽڵ� p ��ֵ����ô�ڵ� p ����һ���ڵ�Ӧ���ڵ�ǰ�ڵ��������
����ǰ�ڵ��ֵ���ڽڵ� p ��ֵ����ô��ǰ�ڵ���п����ǽڵ� p ����һ���ڵ�
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    # ����һ���������
    # def inorderSuccessor(self, root: 'TreeNode', p: 'TreeNode') -> 'TreeNode':
    #     self.pre = None
    #     self.ans = None

    #     def inorder(root: 'TreeNode'):
    #         if not root: return
    #         inorder(root.left)
    #         if self.pre == p:
    #             self.ans = root
    #         self.pre = root
    #         inorder(root.right)

    #     inorder(root)
    #     return self.ans

    # ������������������������
    def inorderSuccessor(self, root: 'TreeNode', p: 'TreeNode') -> 'TreeNode':
        ans = None
        while root:
            # ����ǰ�ڵ�ֵ���ڽڵ� p
            if root.val > p.val:
                ans = root
                # ����Ѱ�Ҹ�С��Ԫ��
                root = root.left
            else:
                # ����Ѱ�Ҹ����Ԫ��
                root = root.right
        return ans
