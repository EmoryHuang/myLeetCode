'''
Descroption: LeetCode 429. N �����Ĳ������
Author: EmoryHuang
Date: 2021-06-01 20:34:00
����˼·:
�����������
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
