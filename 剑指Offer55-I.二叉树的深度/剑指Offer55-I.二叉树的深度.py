'''
Descroption: ��ָ Offer 55 - I. �����������
Author: EmoryHuang
Date: 2021-07-05 22:21:58
����˼·:
����һ���ݹ�
���������������˼·
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    # �ݹ�
    # def maxDepth(self, root: TreeNode) -> int:
    #     return 0 if not root else 1 + max(self.maxDepth(root.left), self.maxDepth(root.right))

    # ��α���
    def maxDepth(self, root: TreeNode) -> int:
        if not root:
            return 0
        q = deque()
        q.append(root)
        ans = 0
        while q:
            n = len(q)
            ans += 1
            for _ in range(n):
                node = q.popleft()
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
        return ans
