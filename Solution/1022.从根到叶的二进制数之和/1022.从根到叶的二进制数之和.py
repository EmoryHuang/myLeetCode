'''
Descroption: LeetCode 1022. �Ӹ���Ҷ�Ķ�������֮��
Author: EmoryHuang
Date: 2022-05-30 12:42:24
Method:
dfs
���⣬dfs ����ÿ��·���ĺ�
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def sumRootToLeaf(self, root: Optional[TreeNode]) -> int:
        def dfs(node: TreeNode, cur: int):
            if node is None:
                return 0
            cur = cur << 1 | node.val
            # �����Ҷ�ӽ�㣬�򷵻�·���ϵ�ֵ
            if node.left is None and node.right is None:
                return cur
            # �ݹ�
            return dfs(node.left, cur) + dfs(node.right, cur)

        return dfs(root, 0)
