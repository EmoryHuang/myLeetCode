'''
Descroption: LeetCode 1261. 在受污染的二叉树中查找元素
Author: EmoryHuang
Date: 2021-09-10 15:07:56
Method:
简单题，dfs还原树，同时记录值
查找target是否存在即可
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class FindElements:
    def __init__(self, root: TreeNode):
        self.st = set()

        def dfs(root, val):
            if not root: return
            root.val = val
            self.st.add(val)
            dfs(root.left, 2 * val + 1)
            dfs(root.right, 2 * val + 2)

        dfs(root, 0)

    def find(self, target: int) -> bool:
        return target in self.st


# Your FindElements object will be instantiated and called as such:
# obj = FindElements(root)
# param_1 = obj.find(target)