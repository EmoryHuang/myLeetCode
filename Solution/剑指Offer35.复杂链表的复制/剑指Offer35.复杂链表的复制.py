'''
Descroption: 剑指 Offer 35. 复杂链表的复制
Author: EmoryHuang
Date: 2021-07-23 19:19:49
解题思路:
回溯 + 哈希表
使用哈希表存储出现过的节点
如果当前节点已经被拷贝过，那么就直接返回
如果当前节点的 next 和 random 都没有被创建，就递归地进行创建
'''

"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        def copyList(node: 'Node', mp):
            if not node:
                return None
            if node in mp:
                return mp[node]
            copy = Node(node.val)
            mp[node] = copy
            copy.next = copyList(node.next, mp)
            copy.random = copyList(node.random, mp)
            return copy

        return copyList(head, {})
