'''
Descroption: LeetCode 508. 出现次数最多的子树元素和
Author: EmoryHuang
Date: 2022-06-19 11:10:40
Method:
使用dfs计算子树元素和
哈希表统计子树元素和出现次数
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
            # 计算子树元素和
            sum = dfs(node.right) + dfs(node.left) + node.val
            cnt[sum] += 1
            return sum

        cnt = Counter()
        dfs(root)
        return [k for k, v in cnt.items() if v == max(cnt.values())]