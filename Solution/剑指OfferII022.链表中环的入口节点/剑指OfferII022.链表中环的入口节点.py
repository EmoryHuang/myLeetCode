'''
Descroption: ��ָ Offer II 022. �����л�����ڽڵ�
Author: EmoryHuang
Date: 2021-08-03 20:09:36
Method:
���ȴ�������ָ�룬�ж������Ƿ���ڻ�
Ȼ���ҵ��뻷��㣬
��������ָ�룬һ��һ������ָ��ÿ��ֻ�ƶ�һ��������ָ��ÿ���ƶ�������
�����ָ�뷴����׷����ָ�룬��˵��������Ϊ�������������ָ�뽫��������β����������Ϊ��������
'''

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        slow, fast = head, head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                fast = head
                while slow != fast:
                    slow = slow.next
                    fast = fast.next
                return fast
        return None