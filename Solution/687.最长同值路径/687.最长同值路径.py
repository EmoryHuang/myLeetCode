'''
Descroption: LeetCode 687. 最长同值路径
Author: EmoryHuang
Date: 2022-09-02 09:17:35
Method:
dfs
分别获取左右节点的最长同值路径
若左孩子非空并且左孩子的值等于当前节点的值，则更新长度加1，右孩子同理
维护ans, ans = max(ans, leftmax + rightmax)
'''

class Solution:
    def longestUnivaluePath(self, root: Optional[TreeNode]) -> int:
        def dfs(node):
            if node is None:
                return 0
            left = dfs(node.left)
            right = dfs(node.right)
            leftmax = left + 1 if node.left and node.left.val == node.val else 0
            rightmax = right + 1 if node.right and node.right.val == node.val else 0
            self.ans = max(self.ans, leftmax + rightmax)
            return max(leftmax, rightmax)

        self.ans = 0
        dfs(root)
        return self.ans
