'''
Descroption: LeetCode 450. 删除二叉搜索树中的节点
Author: EmoryHuang
Date: 2022-06-02 09:06:34
Method:
递归
如果目标节点大于当前节点值，则去右子树中删除，否则去左子树中删除
如果目标节点就是当前节点：
1. 其无左子：其右子顶替其位置，删除了该节点
2. 其无右子：其左子顶替其位置，删除了该节点
3. 其左右子节点都有：其左子树转移到其右子树的最左节点的左子树上，然后右子树顶替其位置
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        if not root:
            return None
        if root.val > key:
            # 左子树删除
            root.left = self.deleteNode(root.left, key)
        elif root.val < key:
            # 右子树删除
            root.right = self.deleteNode(root.right, key)
        else:
            # 节点无左孩子
            if not root.left:
                return root.right
            # 节点无右孩子
            if not root.right:
                return root.left
            # 节点有左右孩子
            cur = root.right
            while cur.left:  # 右子树的最左节点
                cur = cur.left
            cur.left = root.left
            root = root.right
        return root