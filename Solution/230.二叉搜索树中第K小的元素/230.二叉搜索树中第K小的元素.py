'''
Descroption: LeetCode 230. �����������е�KС��Ԫ��
Author: EmoryHuang
Date: 2021-10-17 12:57:15
Method:
����һ���������
�����������������֮������������У�ȡ�� k - 1 ��Ԫ�ؼ���

��������������� + ��֦
�������ֻ��Ҫ�������� k ��Ԫ��
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    # ����һ���������
    # def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
    #     def inorder(node: TreeNode):
    #         if node:
    #             inorder(node.left)
    #             nums.append(node.val)
    #             inorder(node.right)

    #     nums = []
    #     inorder(root)
    #     return nums[k - 1]

    # ��������������� + ��֦
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
