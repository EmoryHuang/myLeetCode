'''
Descroption: LeetCode 430. ��ƽ���༶˫������
Author: EmoryHuang
Date: 2021-09-24 10:56:18
Method:
dfs
������Ҫ�� child ָ���������� node �� node.next ֮��
�� child �ǿգ������ȴ������½������������
node �� child ������node.next �� child_last ����
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
            # ��¼��������һ���ڵ�
            last = None
            while cur:
                # ��¼ next
                nxt = cur.next
                # ��������ӽڵ㣬��ô�ȴ����ӽڵ�
                if cur.child:
                    child_last = dfs(cur.child)
                    # ��ƽ������ cur �� child ����
                    cur.next = cur.child
                    cur.child.prev = cur
                    cur.child = None
                    # ��� next �ǿգ��ͽ���������������һ���ڵ�����
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