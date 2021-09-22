'''
Descroption: LeetCode 725. �ָ�����
Author: EmoryHuang
Date: 2021-09-22 15:45:37
Method:
���ȱ���������¼������
���ÿ��ƽ����������Ҫ������ӵ�����������
֮���ٴα����������������Ԫ�ؼ��ɣ����������������ʽ
'''

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:
    def splitListToParts(self, head: ListNode, k: int) -> List[ListNode]:
        p, n = head, 0
        while p:
            n, p = n + 1, p.next
        # ÿ��ƽ����������Ҫ������ӵ�����������
        avg, add = n // k, n % k
        ans, p = [None] * k, head
        for i in range(k):
            if not p:
                break
            length = avg + (1 if add > 0 else 0)
            add -= 1
            ans[i] = p
            for _ in range(length - 1):
                p = p.next
            p.next, p = None, p.next
        return ans
