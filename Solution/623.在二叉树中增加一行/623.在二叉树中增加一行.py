'''
Descroption: LeetCode 623. �ڶ�����������һ��
Author: EmoryHuang
Date: 2021-08-16 19:39:15
Method:
��������������� depth - 1 ��ʱ������µĽڵ�
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def addOneRow(self, root: TreeNode, val: int, depth: int) -> TreeNode:
        if depth == 1:
            new = TreeNode(val)
            new.left = root
            return new
        q = deque([root])
        cur_depth = 1
        while q:
            n = len(q)
            for _ in range(n):
                node = q.popleft()
                if cur_depth == depth - 1:
                    node.left, node.left.left = TreeNode(val), node.left
                    node.right, node.right.right = TreeNode(val), node.right
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            cur_depth += 1
        return root