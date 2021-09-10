'''
Descroption: LeetCode 1609. ��ż��
Author: EmoryHuang
Date: 2021-07-24 14:02:37
����˼·:
������ȱ���
��¼�ڵ���ȣ���¼ǰһ���ڵ�Ĵ�С
�ж��Ƿ�������Ϊż�ҽڵ㲻Ϊ����ϸ���������Ϊ���ҽڵ㲻Ϊż���ϸ�ݼ�
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isEvenOddTree(self, root: TreeNode) -> bool:
        deep = 0  # ��¼�ڵ����
        pre = 0  # ��¼ǰһ���ڵ�Ĵ�С
        q = deque()
        q.append(root)
        while q:
            n = len(q)
            preo = -1
            pree = 1000001
            for i in range(n):
                node = q.popleft()
                # ���Ϊż�ҽڵ㲻Ϊ����ϸ����
                if deep % 2 == 0:
                    if node.val % 2 == 0 or node.val <= preo:
                        return False
                # ���Ϊ���ҽڵ㲻Ϊż���ϸ�ݼ�
                else:
                    if node.val % 2 == 1 or node.val >= pree:
                        return False
                preo = pree = node.val
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            deep += 1
        return True
