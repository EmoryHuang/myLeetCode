'''
Descroption: LeetCode 105. 从前序与中序遍历序列构造二叉树
Author: EmoryHuang
Date: 2021-06-28 17:05:00
解题思路:
根据中序遍历和先序遍历重建二叉树
采用递归的方法
先序遍历的最左边的节点是根节点，
然后再到中序遍历中找到根节点的位置，它将左右子树一分为二
'''


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if not preorder or not inorder:
            return None
        # 根节点为前序的第一个元素
        root = TreeNode(preorder[0])
        # 在中序中找到根节点的位置
        mid = inorder.index(preorder[0])
        # 构建左子树和右子树
        root.left = self.buildTree(preorder[1:mid + 1], inorder[:mid])
        root.right = self.buildTree(preorder[mid + 1:], inorder[mid + 1:])
        return root
