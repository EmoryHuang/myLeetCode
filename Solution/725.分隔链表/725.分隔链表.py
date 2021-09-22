'''
Descroption: LeetCode 725. 分隔链表
Author: EmoryHuang
Date: 2021-09-22 15:45:37
Method:
首先遍历链表，记录链表长度
获得每组平均数量，需要额外添加的数量的组数
之后再次遍历链表，按规则填充元素即可，另外主义输出的形式
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
        # 每组平均数量，需要额外添加的数量的组数
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
