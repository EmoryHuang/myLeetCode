'''
Descroption: 剑指 Offer II 053. 二叉搜索树中的中序后继
Author: EmoryHuang
Date: 2021-09-08 15:43:49
Method:
方法一：中序遍历
中序遍历，记录节点的前驱，中序遍历找到指定节点后的下一个节点

方法二：二叉搜索树的性质
若当前节点的值小于等于节点 p 的值，那么节点 p 的下一个节点应该在当前节点的右子树
若当前节点的值大于节点 p 的值，那么当前节点就有可能是节点 p 的下一个节点
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    # 方法一：中序遍历
    # def inorderSuccessor(self, root: 'TreeNode', p: 'TreeNode') -> 'TreeNode':
    #     self.pre = None
    #     self.ans = None

    #     def inorder(root: 'TreeNode'):
    #         if not root: return
    #         inorder(root.left)
    #         if self.pre == p:
    #             self.ans = root
    #         self.pre = root
    #         inorder(root.right)

    #     inorder(root)
    #     return self.ans

    # 方法二：二叉搜索树的性质
    def inorderSuccessor(self, root: 'TreeNode', p: 'TreeNode') -> 'TreeNode':
        ans = None
        while root:
            # 若当前节点值大于节点 p
            if root.val > p.val:
                ans = root
                # 向左寻找更小的元素
                root = root.left
            else:
                # 向右寻找更大的元素
                root = root.right
        return ans
