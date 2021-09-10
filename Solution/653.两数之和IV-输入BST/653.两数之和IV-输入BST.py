'''
Descroption: LeetCode 653. 两数之和 IV - 输入 BST
Author: EmoryHuang
Date: 2021-06-02 12:30:00
解题思路:
方法一：使用set
使用set记录数组元素

方法二：中序遍历 + 双指针
通过中序遍历的到顺序的数组，然后再寻找和为 k 的数
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    # 方法一：使用set
    # def findTarget(self, root: TreeNode, k: int) -> bool:
    #     hash = set()

    #     def find(root: TreeNode, k: int):
    #         if not root:
    #             return False
    #         if k - root.val in hash:
    #             return True
    #         hash.add(root.val)
    #         return find(root.left, k) or find(root.right, k)
    #     return find(root, k)

    # 方法二：中序遍历 + 双指针
    def findTarget(self, root: TreeNode, k: int) -> bool:
        list = []

        def inorder(root: TreeNode):
            if root:
                inorder(root.left)
                list.append(root.val)
                inorder(root.right)

        inorder(root)
        l, r = 0, len(list)-1
        while l < r:
            if list[l] + list[r] == k:
                return True
            elif list[l] + list[r] > k:
                r -= 1
            else:
                l += 1
        return False
