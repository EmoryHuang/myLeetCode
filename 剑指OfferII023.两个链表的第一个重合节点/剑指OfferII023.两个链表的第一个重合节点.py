'''
Descroption: 剑指 Offer II 023. 两个链表的第一个重合节点
Author: EmoryHuang
Date: 2021-08-03 20:23:58
Method:
用一个指针指向链表 A 头结点，另一个指针指向链表 B 头结点，
然后同时移动，当遍历到链表尾时指针换到另一条链表，当两个指针相遇时就是相交点
'''

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        ha, hb = headA, headB
        if not ha or not hb: return None
        while ha != hb:
            ha = ha.next if ha else headB
            hb = hb.next if hb else headA
        return ha