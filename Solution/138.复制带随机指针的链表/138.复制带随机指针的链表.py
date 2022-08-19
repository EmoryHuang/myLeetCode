'''
Descroption: LeetCode 138. ���ƴ����ָ�������
Author: EmoryHuang
Date: 2021-07-22 14:06:07
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
        def copyList(node: 'Node', ans):
            if not node:
                return None
            if node in ans:
                return ans[node]
            copy = Node(node.val)
            ans[node] = copy
            copy.next = copyList(node.next, ans)
            copy.random = copyList(node.random, ans)
            return copy

        return copyList(head, {})
