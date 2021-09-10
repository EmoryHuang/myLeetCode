'''
Descroption: ��ָ Offer 32 - I. ���ϵ��´�ӡ������
Author: EmoryHuang
Date: 2021-07-03 13:32:33
����˼·:
���ղ�������ķ�����ӡ����
'''


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[int]:
        if not root:
            return []
        ans = []
        q = deque()
        q.append(root)
        while q:
            node = q.popleft()
            ans.append(node.val)
            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)
        return ans
