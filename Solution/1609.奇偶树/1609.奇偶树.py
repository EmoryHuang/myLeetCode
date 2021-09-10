'''
Descroption: LeetCode 1609. 奇偶树
Author: EmoryHuang
Date: 2021-07-24 14:02:37
解题思路:
广度优先遍历
记录节点深度，记录前一个节点的大小
判断是否出现深度为偶且节点不为奇或不严格递增，深度为奇且节点不为偶或不严格递减
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isEvenOddTree(self, root: TreeNode) -> bool:
        deep = 0  # 记录节点深度
        pre = 0  # 记录前一个节点的大小
        q = deque()
        q.append(root)
        while q:
            n = len(q)
            preo = -1
            pree = 1000001
            for i in range(n):
                node = q.popleft()
                # 深度为偶且节点不为奇或不严格递增
                if deep % 2 == 0:
                    if node.val % 2 == 0 or node.val <= preo:
                        return False
                # 深度为奇且节点不为偶或不严格递减
                else:
                    if node.val % 2 == 1 or node.val >= pree:
                        return False
                preo = pree = node.val
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            deep += 1
        return True
