'''
Descroption: LeetCode 652. 寻找重复的子树
Author: EmoryHuang
Date: 2022-09-05 10:28:30
Method:
dfs
将子树进行序列化表示，作为key，并存入哈希表
若出现相同key则认为出现重复子树
'''


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findDuplicateSubtrees(self, root: Optional[TreeNode]) -> List[Optional[TreeNode]]:
        def dfs(node):
            if not node:
                return ""
            key = f'{node.val}({dfs(node.left)})({dfs(node.right)})'
            subtree = m.get(key, None)
            if subtree:
                ans.add(subtree)
            else:
                m[key] = node
            return key

        m = defaultdict(str)
        ans = set()
        dfs(root)
        return ans