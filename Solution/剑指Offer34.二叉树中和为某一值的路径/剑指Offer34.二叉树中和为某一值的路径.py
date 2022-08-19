'''
Descroption: ��ָ Offer 34. �������к�Ϊĳһֵ��·��
Author: EmoryHuang
Date: 2021-07-03 15:10:01
����˼·:
dfs����
ö��ÿһ���Ӹ��ڵ㵽Ҷ�ӽڵ��·��
��������Ҷ�ӽڵ㣬�Ҵ�ʱ·����ǡΪĿ���ʱ�����ҵ���һ��·��
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def pathSum(self, root, target):
        ans = []
        path = []

        def dfs(root, num):
            if not root:
                return
            num -= root.val
            path.append(root.val)
            if not root.left and not root.right and num == 0:
                ans.append(path[:])
            dfs(root.left, num)
            dfs(root.right, num)
            path.pop()
        dfs(root, target)
        return ans
