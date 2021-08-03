'''
Descroption: ��ָ Offer II 023. ��������ĵ�һ���غϽڵ�
Author: EmoryHuang
Date: 2021-08-03 20:23:58
Method:
��һ��ָ��ָ������ A ͷ��㣬��һ��ָ��ָ������ B ͷ��㣬
Ȼ��ͬʱ�ƶ���������������βʱָ�뻻����һ������������ָ������ʱ�����ཻ��
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