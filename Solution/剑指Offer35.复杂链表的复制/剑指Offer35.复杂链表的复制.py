'''
Descroption: ��ָ Offer 35. ��������ĸ���
Author: EmoryHuang
Date: 2021-07-23 19:19:49
����˼·:
���� + ��ϣ��
ʹ�ù�ϣ��洢���ֹ��Ľڵ�
�����ǰ�ڵ��Ѿ�������������ô��ֱ�ӷ���
�����ǰ�ڵ�� next �� random ��û�б��������͵ݹ�ؽ��д���
'''

"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        def copyList(node: 'Node', mp):
            if not node:
                return None
            if node in mp:
                return mp[node]
            copy = Node(node.val)
            mp[node] = copy
            copy.next = copyList(node.next, mp)
            copy.random = copyList(node.random, mp)
            return copy

        return copyList(head, {})
