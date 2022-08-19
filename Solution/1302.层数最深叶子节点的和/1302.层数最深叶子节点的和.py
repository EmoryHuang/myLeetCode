'''
Descroption: LeetCode 1302. 层数最深叶子节点的和
Author: EmoryHuang
Date: 2021-07-19 19:10:35
解题思路:
层序遍历，计算每层的节点之和
'''


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def deepestLeavesSum(self, root: TreeNode) -> int:
        q = deque()
        q.append(root)
        while q:
            n = len(q)
            ans = 0
            for _ in range(n):
                node = q.popleft()
                ans += node.val
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
        return ans
