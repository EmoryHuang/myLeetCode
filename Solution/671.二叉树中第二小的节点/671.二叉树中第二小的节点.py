'''
Descroption: LeetCode 671. �������еڶ�С�Ľڵ�
Author: EmoryHuang
Date: 2021-07-27 13:48:36
Method:
���ڵ�һ��С�ڵ��������ӽڵ㣬�������ĸ��ڵ�Ϊ��С�Ľڵ�
��ô��Ŀ�ͱ������������������С�Ľڵ�
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def findSecondMinimumValue(self, root: TreeNode) -> int:
        def dfs(node: TreeNode, val: int) -> int:
            if not node:
                return -1
            if node.val > val:
                return node.val
            l = dfs(node.left, val)
            r = dfs(node.right, val)
            # ���������ӽڵ�
            if l > val and r > val:
                return min(l, r)
            # �������ӽڵ�
            return max(l, r)

        return dfs(root, root.val)
