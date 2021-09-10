'''
Descroption: 剑指 Offer 32 - I. 从上到下打印二叉树
Author: EmoryHuang
Date: 2021-07-03 13:32:33
解题思路:
按照层序遍历的方法打印即可
'''


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[int]:
        if not root:
            return []
        ans = []
        q = deque()
        q.append(root)
        while q:
            node = q.popleft()
            ans.append(node.val)
            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)
        return ans
