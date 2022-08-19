'''
Descroption: 剑指 Offer 32 - III. 从上到下打印二叉树 III
Author: EmoryHuang
Date: 2021-07-03 14:08:11
解题思路:
按照层序遍历的方法打印即可
然后按照要求反转或前插
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        ans = []
        if not root:
            return ans
        q = deque()
        q.append(root)
        while q:
            n = len(q)
            tmp = []
            for _ in range(n):
                node = q.popleft()
                tmp.append(node.val)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            if len(ans) % 2:
                tmp.reverse()
            ans.append(tmp)
        return ans
