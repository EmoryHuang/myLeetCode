'''
Descroption: ��ָ Offer II 029. �����ѭ������
Author: EmoryHuang
Date: 2022-06-18 09:04:55
Method:
����ѭ���б��Ƚ�Ԫ�ص�ֵ�����뵽���ʵ�λ�ã���Ҫ��Ҫ�߽�������
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
        # �� head Ϊ�գ���ֱ�Ӳ���
        if head is None:
            new.next = new
            return new
        # ��ֻ��һ���ڵ㣬��ֱ�Ӳ���
        if head.next == head:
            head.next = new
            new.next = head
            return head
        cur = head
        # Ѱ�Ҳ���λ��
        while cur.next != head:
            if cur.val <= insertVal <= cur.next.val:
                break
            if cur.val > cur.next.val:
                if insertVal > cur.val or insertVal < cur.next.val:
                    break
            cur = cur.next
        # ����
        new.next = cur.next
        cur.next = new
        return head
