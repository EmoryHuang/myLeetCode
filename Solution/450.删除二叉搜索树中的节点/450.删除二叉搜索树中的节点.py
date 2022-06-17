'''
Descroption: LeetCode 450. ɾ�������������еĽڵ�
Author: EmoryHuang
Date: 2022-06-02 09:06:34
Method:
�ݹ�
���Ŀ��ڵ���ڵ�ǰ�ڵ�ֵ����ȥ��������ɾ��������ȥ��������ɾ��
���Ŀ��ڵ���ǵ�ǰ�ڵ㣺
1. �������ӣ������Ӷ�����λ�ã�ɾ���˸ýڵ�
2. �������ӣ������Ӷ�����λ�ã�ɾ���˸ýڵ�
3. �������ӽڵ㶼�У���������ת�Ƶ���������������ڵ���������ϣ�Ȼ��������������λ��
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        if not root:
            return None
        if root.val > key:
            # ������ɾ��
            root.left = self.deleteNode(root.left, key)
        elif root.val < key:
            # ������ɾ��
            root.right = self.deleteNode(root.right, key)
        else:
            # �ڵ�������
            if not root.left:
                return root.right
            # �ڵ����Һ���
            if not root.right:
                return root.left
            # �ڵ������Һ���
            cur = root.right
            while cur.left:  # ������������ڵ�
                cur = cur.left
            cur.left = root.left
            root = root.right
        return root