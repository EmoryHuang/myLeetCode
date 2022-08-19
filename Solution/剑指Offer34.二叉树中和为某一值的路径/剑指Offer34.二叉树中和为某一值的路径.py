'''
Descroption: 剑指 Offer 34. 二叉树中和为某一值的路径
Author: EmoryHuang
Date: 2021-07-03 15:10:01
解题思路:
dfs回溯
枚举每一条从根节点到叶子节点的路径
若遍历到叶子节点，且此时路径和恰为目标和时，就找到了一条路径
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def pathSum(self, root, target):
        ans = []
        path = []

        def dfs(root, num):
            if not root:
                return
            num -= root.val
            path.append(root.val)
            if not root.left and not root.right and num == 0:
                ans.append(path[:])
            dfs(root.left, num)
            dfs(root.right, num)
            path.pop()
        dfs(root, target)
        return ans
