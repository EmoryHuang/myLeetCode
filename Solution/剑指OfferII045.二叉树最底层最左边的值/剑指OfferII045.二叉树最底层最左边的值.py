'''
Descroption: 剑指 Offer II 045. 二叉树最底层最左边的值
Author: EmoryHuang
Date: 2021-08-04 20:03:22
Method:
层序遍历，每遍历一层，则更新每层的第一个端点
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def findBottomLeftValue(self, root: TreeNode) -> int:
        q = deque([root])
        ans = root.val
        while q:
            n = len(q)
            flag = False
            for _ in range(n):
                node = q.popleft()
                if not flag:
                    ans = node.val
                    flag = True
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
        return ans
