'''
Descroption: ��ָ Offer II 046. ���������Ҳ���ͼ
Author: EmoryHuang
Date: 2021-08-04 20:12:28
Method:
���������ÿ����һ�㣬��¼ÿ�����һ���˵�
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        if not root:
            return []
        q = deque([root])
        ans = []
        while q:
            n = len(q)
            ans.append(q[-1].val)
            for _ in range(n):
                node = q.popleft()
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
        return ans
