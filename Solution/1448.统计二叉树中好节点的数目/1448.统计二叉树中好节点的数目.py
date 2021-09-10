'''
Descroption: LeetCode 1448. ͳ�ƶ������кýڵ����Ŀ
Author: EmoryHuang
Date: 2021-08-23 17:10:24
Method:
dfs
������ǰ�������ͬʱά����ǰ·���ϵ����ֵ
����ǰ�ڵ�ֵ���ڵ���·���ϵĽڵ�ֵ����ôans + 1
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        self.ans = 0

        def dfs(root: TreeNode, n: int) -> None:
            if root.val >= n:
                self.ans += 1
                n = root.val
            if root.left: dfs(root.left, n)
            if root.right: dfs(root.right, n)

        dfs(root, root.val)
        return self.ans
