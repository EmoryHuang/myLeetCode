'''
Descroption: LeetCode 429. N 叉树的层序遍历
Author: EmoryHuang
Date: 2021-06-01 20:34:00
解题思路:
广度优先搜索
'''

"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""


class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        if not root:
            return []
        ans = []
        queue = [root]
        while queue:
            cur = []
            ans.append([])
            for node in queue:
                ans[-1].append(node.val)
                cur.extend(node.children)
            queue = cur
        return ans
