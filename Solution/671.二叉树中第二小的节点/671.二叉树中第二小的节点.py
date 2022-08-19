'''
Descroption: LeetCode 671. 二叉树中第二小的节点
Author: EmoryHuang
Date: 2021-07-27 13:48:36
Method:
根节点一定小于等于左右子节点，二叉树的根节点为最小的节点
那么题目就变成了求左右子树中最小的节点
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
            # 存在两个子节点
            if l > val and r > val:
                return min(l, r)
            # 不存在子节点
            return max(l, r)

        return dfs(root, root.val)
