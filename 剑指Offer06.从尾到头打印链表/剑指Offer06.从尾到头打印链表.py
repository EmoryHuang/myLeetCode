'''
Descroption: ��ָ Offer 06. ��β��ͷ��ӡ����
Author: EmoryHuang
Date: 2021-06-28 17:03:00
����˼·:
���⣬reverse, �ݹ�, ջ
'''


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # reverse
    def reversePrint(self, head: ListNode) -> List[int]:
        ans = []
        while head != None:
            ans.append(head.val)
            head = head.next
        return ans[::-1]

    # �ݹ�
    # def reversePrint(self, head: ListNode) -> List[int]:
    #     if head is None:
    #         return []
    #     return self.reversePrint(head.next) + [head.val]
