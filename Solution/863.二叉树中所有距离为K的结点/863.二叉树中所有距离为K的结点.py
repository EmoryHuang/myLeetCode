'''
Descroption: 
Author: EmoryHuang
Date: 2021-07-28 12:30:50
Method: 
'''
'''
Descroption: LeetCode 863. �����������о���Ϊ K �Ľ��
Author: EmoryHuang
Date: 2021-07-28 13:35:33
Method:
����ÿ���ڵ��ֵ������ͬ��������ǿ���ʹ�ù�ϣ���¼ÿ���ڵ�ĸ��ڵ�
Ȼ���Ŀ��ڵ����������������ȱ����������������Ͻ�������
�ҵ����Ϊk�Ľڵ�
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> List[int]:
        parents = defaultdict(list)
        ans = []

        def find_parent(root: TreeNode) -> None:
            if root.left:
                parents[root.left.val] = root
                find_parent(root.left)
            if root.right:
                parents[root.right.val] = root
                find_parent(root.right)

        def find_deep_k(node: TreeNode, parent: TreeNode, depth: int) -> None:
            if not node:
                return
            if depth == k:
                ans.append(node.val)
                return
            if node.left != parent:
                find_deep_k(node.left, node, depth + 1)
            if node.right != parent:
                find_deep_k(node.right, node, depth + 1)
            if parents[node.val] != parent:
                find_deep_k(parents[node.val], node, depth + 1)

        find_parent(root)
        find_deep_k(target, None, 0)
        return ans
