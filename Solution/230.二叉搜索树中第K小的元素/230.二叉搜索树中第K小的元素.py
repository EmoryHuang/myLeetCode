'''
Descroption: LeetCode 230. 二叉搜索树中第K小的元素
Author: EmoryHuang
Date: 2021-10-17 12:57:15
Method:
方法一：中序遍历
二叉搜索树中序遍历之后就是有序数列，取第 k - 1 个元素即可

方法二：中序遍历 + 剪枝
中序遍历只需要遍历到第 k 个元素
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    # 方法一：中序遍历
    # def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
    #     def inorder(node: TreeNode):
    #         if node:
    #             inorder(node.left)
    #             nums.append(node.val)
    #             inorder(node.right)

    #     nums = []
    #     inorder(root)
    #     return nums[k - 1]

    # 方法二：中序遍历 + 剪枝
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        def inorder(node: TreeNode):
            if node and self.k > 0:
                inorder(node.left)
                self.k -= 1
                if self.k == 0:
                    self.ans = node.val
                inorder(node.right)

        self.ans = 0
        self.k = k
        inorder(root)
        return self.ans
