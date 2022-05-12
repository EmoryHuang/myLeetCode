'''
Descroption: LeetCode 449. ���л��ͷ����л�����������
Author: EmoryHuang
Date: 2022-05-11 08:52:30
Method:
ʹ������������л�
��������������֮��Ϊ����������У������л���ͨ������������к�����������й�������������
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Codec:
    def serialize(self, root: TreeNode) -> str:
        """Encodes a tree to a single string.
        """

        # �������
        def preorder(root):
            if root:
                res.append(root.val)
                preorder(root.left)
                preorder(root.right)

        res = []
        preorder(root)
        return ','.join(map(str, res))

    def deserialize(self, data: str) -> TreeNode:
        """Decodes your encoded data to tree.
        """
        if not data:
            return None
        # �����������
        pre_order = list(map(int, data.split(',')))
        # ��������������֮��Ϊ�����������
        in_order = sorted(pre_order)

        def build(pre_order, in_order):
            if not pre_order:
                return None
            mid = pre_order[0]
            idx = in_order.index(mid)
            root = TreeNode(mid)
            root.left = build(pre_order[1:idx + 1], in_order[:idx])
            root.right = build(pre_order[idx + 1:], in_order[idx + 1:])
            return root

        return build(pre_order, in_order)


# Your Codec object will be instantiated and called as such:
# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# tree = ser.serialize(root)
# ans = deser.deserialize(tree)
# return ans