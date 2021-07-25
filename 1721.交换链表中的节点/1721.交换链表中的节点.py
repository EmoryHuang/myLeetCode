'''
Descroption: LeetCode 1721. ���������еĽڵ�
Author: EmoryHuang
Date: 2021-07-25 13:50:11
Method:
����ָ��
��ָ������ǰ��k - 1���ڵ㣬Ȼ�����ָ��ͬʱǰ��
�ҵ�������k���ڵ�
'''

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def swapNodes(self, head: ListNode, k: int) -> ListNode:
        fast, slow = head, head
        # �ҵ�������k���ڵ�
        for _ in range(k - 1):
            fast = fast.next
        l = fast
        # �ҵ�������k���ڵ�
        while fast.next:
            slow = slow.next
            fast = fast.next
        l.val, slow.val = slow.val, l.val
        return head
