'''
Descroption: LeetCode 508. ���ִ�����������Ԫ�غ�
Author: EmoryHuang
Date: 2022-06-19 11:10:40
Method:
ʹ��dfs��������Ԫ�غ�
��ϣ��ͳ������Ԫ�غͳ��ִ���
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def findFrequentTreeSum(self, root: TreeNode) -> List[int]:
        def dfs(node):
            if not node:
                return 0
            # ��������Ԫ�غ�
            sum = dfs(node.right) + dfs(node.left) + node.val
            cnt[sum] += 1
            return sum

        cnt = Counter()
        dfs(root)
        return [k for k, v in cnt.items() if v == max(cnt.values())]