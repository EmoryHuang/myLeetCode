'''
Descroption: LeetCode 337. 打家劫舍 III
Author: EmoryHuang
Date: 2021-07-11 14:16:58
解题思路:
如果是偷当前节点，那么左右孩子就不能偷
如果是不偷当前节点，那么左右孩子可偷可不偷，取最大值
当前节点的状态就是 (偷的金额，不偷的金额)
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
                # (偷的金额，不偷的金额)
                return [0, 0]
            left = dfs(root.left)
            right = dfs(root.right)
            # 0 表示偷，1表示不偷
            # 偷当前节点，不偷子节点
            val1 = root.val + left[1] + right[1]
            # 不偷当前节点，不偷/偷子节点
            val2 = max(left[0], left[1]) + max(right[0], right[1])
            return [val1, val2]

        ans = dfs(root)
        return max(ans[0], ans[1])
