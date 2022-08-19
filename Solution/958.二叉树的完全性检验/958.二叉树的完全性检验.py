'''
Descroption: LeetCode 958. ����������ȫ�Լ���
Author: EmoryHuang
Date: 2021-07-10 14:25:27
����˼·:
�����������������������սڵ㣬�����ı����Ͳ�Ӧ���ҽڵ���
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isCompleteTree(self, root: TreeNode) -> bool:
        q = deque()
        q.append(root)
        flag = False  # flag ��ʶ�Ƿ������սڵ�
        while q:
            node = q.popleft()
            if not node:  # �����ǰ�ڵ�Ϊ��
                flag = True
                continue
            if flag:
                return False
            q.append(node.left)
            q.append(node.right)
        return True
