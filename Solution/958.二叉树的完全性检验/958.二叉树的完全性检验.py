'''
Descroption: LeetCode 958. 二叉树的完全性检验
Author: EmoryHuang
Date: 2021-07-10 14:25:27
解题思路:
二叉树层序遍历，如果遇到空节点，则后面的遍历就不应该右节点了
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isCompleteTree(self, root: TreeNode) -> bool:
        q = deque()
        q.append(root)
        flag = False  # flag 标识是否遇到空节点
        while q:
            node = q.popleft()
            if not node:  # 如果当前节点为空
                flag = True
                continue
            if flag:
                return False
            q.append(node.left)
            q.append(node.right)
        return True
