'''
Descroption: LeetCode 430. 扁平化多级双向链表
Author: EmoryHuang
Date: 2021-09-24 10:56:18
Method:
dfs
我们需要将 child 指向的链表插入 node 和 node.next 之间
若 child 非空，则优先处理，重新进行链表的连接
node 与 child 相连，node.next 与 child_last 相连
'''

"""
# Definition for a Node.
class Node:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
"""

class Solution:
    def flatten(self, head: 'Node') -> 'Node':
        def dfs(node: 'Node') -> 'Node':
            cur = node
            # 记录链表的最后一个节点
            last = None
            while cur:
                # 记录 next
                nxt = cur.next
                # 如果存在子节点，那么先处理子节点
                if cur.child:
                    child_last = dfs(cur.child)
                    # 扁平化，将 cur 与 child 连接
                    cur.next = cur.child
                    cur.child.prev = cur
                    cur.child = None
                    # 如果 next 非空，就将它与子链表的最后一个节点相连
                    if nxt:
                        child_last.next = nxt
                        nxt.prev = child_last
                    last = child_last
                else:
                    last = cur
                cur = nxt
            return last

        dfs(head)
        return head