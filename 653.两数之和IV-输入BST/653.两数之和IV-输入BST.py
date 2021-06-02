'''
Descroption: LeetCode 653. ����֮�� IV - ���� BST
Author: EmoryHuang
Date: 2021-06-02 12:30:00
����˼·:
����һ��ʹ��set
ʹ��set��¼����Ԫ��

��������������� + ˫ָ��
ͨ����������ĵ�˳������飬Ȼ����Ѱ�Һ�Ϊ k ����
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    # ����һ��ʹ��set
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

    # ��������������� + ˫ָ��
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
