'''
Descroption: 剑指 Offer 55 - I. 二叉树的深度
Author: EmoryHuang
Date: 2021-07-05 22:21:58
解题思路:
方法一：递归
方法二：层序遍历思路
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    # 递归
    # def maxDepth(self, root: TreeNode) -> int:
    #     return 0 if not root else 1 + max(self.maxDepth(root.left), self.maxDepth(root.right))

    # 层次遍历
    def maxDepth(self, root: TreeNode) -> int:
        if not root:
            return 0
        q = deque()
        q.append(root)
        ans = 0
        while q:
            n = len(q)
            ans += 1
            for _ in range(n):
                node = q.popleft()
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
        return ans
