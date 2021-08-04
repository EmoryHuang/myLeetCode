'''
Descroption: ��ָ Offer II 044. ������ÿ������ֵ
Author: EmoryHuang
Date: 2021-08-04 19:55:48
Method:
�����������¼ÿ������ֵ
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def largestValues(self, root: TreeNode) -> List[int]:
        if not root:
            return []
        ans = []
        q = deque([root])
        while q:
            n = len(q)
            maxl = float('-inf')
            for _ in range(n):
                node = q.popleft()
                maxl = max(maxl, node.val)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            ans.append(maxl)
        return ans