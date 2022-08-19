'''
Descroption: LeetCode 337. ��ҽ��� III
Author: EmoryHuang
Date: 2021-07-11 14:16:58
����˼·:
�����͵��ǰ�ڵ㣬��ô���Һ��ӾͲ���͵
����ǲ�͵��ǰ�ڵ㣬��ô���Һ��ӿ�͵�ɲ�͵��ȡ���ֵ
��ǰ�ڵ��״̬���� (͵�Ľ���͵�Ľ��)
'''


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rob(self, root: TreeNode) -> int:

        def dfs(root) -> List[int]:
            if not root:
                # (͵�Ľ���͵�Ľ��)
                return [0, 0]
            left = dfs(root.left)
            right = dfs(root.right)
            # 0 ��ʾ͵��1��ʾ��͵
            # ͵��ǰ�ڵ㣬��͵�ӽڵ�
            val1 = root.val + left[1] + right[1]
            # ��͵��ǰ�ڵ㣬��͵/͵�ӽڵ�
            val2 = max(left[0], left[1]) + max(right[0], right[1])
            return [val1, val2]

        ans = dfs(root)
        return max(ans[0], ans[1])
