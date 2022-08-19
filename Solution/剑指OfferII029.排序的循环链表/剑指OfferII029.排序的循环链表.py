'''
Descroption: 剑指 Offer II 029. 排序的循环链表
Author: EmoryHuang
Date: 2022-06-18 09:04:55
Method:
遍历循环列表，比较元素的值并插入到合适的位置，需要主要边界条件。
'''

"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, next=None):
        self.val = val
        self.next = next
"""


class Solution:
    def insert(self, head: 'Node', insertVal: int) -> 'Node':
        new = Node(insertVal)
        # 若 head 为空，则直接插入
        if head is None:
            new.next = new
            return new
        # 若只有一个节点，则直接插入
        if head.next == head:
            head.next = new
            new.next = head
            return head
        cur = head
        # 寻找插入位置
        while cur.next != head:
            if cur.val <= insertVal <= cur.next.val:
                break
            if cur.val > cur.next.val:
                if insertVal > cur.val or insertVal < cur.next.val:
                    break
            cur = cur.next
        # 插入
        new.next = cur.next
        cur.next = new
        return head
