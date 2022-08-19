'''
Descroption: LeetCode 987. �������Ĵ������
Author: EmoryHuang
Date: 2021-07-31 13:31:33
Method:
dfs + ����
dfs �õ����нڵ�����꣬Ȼ��������
����ͬ�кŵ�Ԫ�ط���ͬһ����
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def verticalTraversal(self, root: TreeNode) -> List[List[int]]:
        nodes = []

        def dfs(node: TreeNode, x: int, y: int) -> None:
            if not node:
                return
            nodes.append([y, x, node.val])
            dfs(node.left, x + 1, y - 1)
            dfs(node.right, x + 1, y + 1)

        # dfs �õ����нڵ������
        dfs(root, 0, 0)
        # ��������
        nodes.sort()
        ans = []
        precol = float('-inf')  # ǰһ���ڵ����
        for y, x, val in nodes:
            # �������ͬһ��
            if y != precol:
                precol = y
                ans.append(list())
            ans[-1].append(val)
        return ans
