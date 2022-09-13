'''
Descroption: LeetCode 669. 修剪二叉搜索树
Author: EmoryHuang
Date: 2022-09-10 10:36:05
Method:
DFS
如果当前节点的值小于 low, 那么说明当前节点及其左子树均不满足，继续对其右子树进行修剪
如果当前节点的值大于 high, 那么说明当前节点及其右子树均不满足，继续对其左子树进行修剪
'''


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def trimBST(self, root: Optional[TreeNode], low: int,
                high: int) -> Optional[TreeNode]:
        if root is None:
            return None
        if root.val < low:
            return self.trimBST(root.right, low, high)
        if root.val > high:
            return self.trimBST(root.left, low, high)
        root.left = self.trimBST(root.left, low, high)
        root.right = self.trimBST(root.right, low, high)
        return root