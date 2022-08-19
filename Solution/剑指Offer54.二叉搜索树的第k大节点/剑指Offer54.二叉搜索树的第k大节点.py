'''
Descroption: ��ָ Offer 54. �����������ĵ�k��ڵ�
Author: EmoryHuang
Date: 2021-10-18 19:25:55
Method:
����һ���������
�����������������֮������������У�ȡ�� n - k ��Ԫ�ؼ���

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
    # def kthLargest(self, root: Optional[TreeNode], k: int) -> int:
    #     def inorder(node: TreeNode):
    #         if node:
    #             inorder(node.left)
    #             nums.append(node.val)
    #             inorder(node.right)

    #     nums = []
    #     inorder(root)
    #     return nums[len(nums) - k]

    # ��������������� + ��֦
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
