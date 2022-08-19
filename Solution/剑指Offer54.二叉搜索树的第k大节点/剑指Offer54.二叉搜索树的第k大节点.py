'''
Descroption: 剑指 Offer 54. 二叉搜索树的第k大节点
Author: EmoryHuang
Date: 2021-10-18 19:25:55
Method:
方法一：中序遍历
二叉搜索树中序遍历之后就是有序数列，取第 n - k 个元素即可

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
    # def kthLargest(self, root: Optional[TreeNode], k: int) -> int:
    #     def inorder(node: TreeNode):
    #         if node:
    #             inorder(node.left)
    #             nums.append(node.val)
    #             inorder(node.right)

    #     nums = []
    #     inorder(root)
    #     return nums[len(nums) - k]

    # 方法二：中序遍历 + 剪枝
    def kthLargest(self, root: Optional[TreeNode], k: int) -> int:
        def inorder(node: TreeNode):
            if node:
                inorder(node.right)
                self.cnt += 1
                if self.cnt == k:
                    self.ans = node.val
                    return
                inorder(node.left)

        self.ans = 0
        self.cnt = 0
        inorder(root)
        return self.ans
