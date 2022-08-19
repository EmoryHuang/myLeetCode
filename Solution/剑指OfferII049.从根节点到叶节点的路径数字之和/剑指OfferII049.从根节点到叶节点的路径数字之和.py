'''
Descroption: ��ָ Offer II 049. �Ӹ��ڵ㵽Ҷ�ڵ��·������֮��
Author: EmoryHuang
Date: 2021-08-06 19:07:19
Method:
���ݷ�
ö��ÿһ���Ӹ��ڵ㵽Ҷ�ӽڵ��·��
��������Ҷ�ӽڵ㣬������·���ĺͼ��� ans
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def sumNumbers(self, root: TreeNode) -> int:
        self.ans = 0

        def dfs(node: TreeNode, cur: int):
            if not node:
                return
            if not node.left and not node.right:
                self.ans += cur * 10 + node.val
            dfs(node.left, cur * 10 + node.val)
            dfs(node.right, cur * 10 + node.val)

        dfs(root, 0)
        return self.ans